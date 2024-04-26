/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_academy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/13 12:04:05 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_list(t_academy *academy)
{
	int		id;
	t_philo	*philo;

	id = 1;
	while (id <= academy->info.num_philos)
	{
		philo = ft_lstnew(id, academy);
		ft_lstadd_back(&academy->list, philo);
		id++;
	}
	ft_lstcircle(&academy->list, ft_lstlast(academy->list));
}

static void	set_threads(t_academy *academy, int even_odd)
{
	t_philo		*philo;
	int			cont;
	int			id;

	philo = academy->list;
	cont = 0;
	id = 1;
	while (id <= academy->info.num_philos)
	{
		if (even_odd == 0 && id % 2 != 0)
			pthread_create(&(academy->threads[cont]), NULL,
				&philosophers, (void *)philo);
		else if (even_odd == 1 && id % 2 == 0)
			pthread_create(&(academy->threads[cont]), NULL,
				&philosophers, (void *)philo);
		id++;
		philo = philo->next;
		cont++;
	}
}

static void	join_threads(t_academy *academy)
{
	int	cont;

	cont = 0;
	while (cont < academy->info.num_philos)
	{
		pthread_join(academy->threads[cont], NULL);
		cont++;
	}
	set_stop(academy->list, 2, 0);
	pthread_join(academy->time_thread, NULL);
}

static void	set_info(t_academy *academy, int args, char **data)
{
	academy->info.num_philos = ft_atoi(data[0]);
	academy->info.time_to_die = ft_atoi(data[1]);
	academy->info.time_to_eat = ft_atoi(data[2]);
	academy->info.time_to_sleep = ft_atoi(data[3]);
	academy->info.start_prog_milisec = 0;
	academy->info.start_checker_microsec = 0;
	academy->info.all_ate = 0;
	academy->info.stop = 0;
	academy->info.print = 0;
	if (args == 5)
	{
		academy->info.num_eats = ft_atoi(data[4]);
		if (academy->info.num_eats == 0)
			academy->info.num_eats = -1;
	}
	else
		academy->info.num_eats = 0;
}

void	set_academy(t_academy *academy, int argc, char **argv)
{
	if (check_int_limits(argv) == 0)
	{
		free_matrix(argv);
		return ;
	}
	set_info(academy, argc, argv);
	free_matrix(argv);
	if (academy->info.num_eats == -1)
		return ;
	pthread_mutex_init(&(academy->print_mutex), NULL);
	pthread_mutex_init(&(academy->stop), NULL);
	pthread_mutex_init(&(academy->all_eats), NULL);
	pthread_mutex_init(&(academy->time), NULL);
	academy->list = NULL;
	set_list(academy);
	academy->threads = malloc(sizeof(pthread_t) * academy->info.num_philos);
	gettimeofday(&academy->info.time_struct, NULL);
	academy->info.start_prog_milisec = get_miliseconds(academy->list);
	pthread_create(&(academy->time_thread), NULL,
		&time_check, (void *)academy);
	set_threads(academy, 0);
	set_threads(academy, 1);
	join_threads(academy);
	end_program(academy);
}
