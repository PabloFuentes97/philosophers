/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_academy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/09 11:24:11 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

static void	set_even_processes(t_academy *academy)
{
	t_philo		*philo;
	int			cont;
	int			id;
	int			pid;

	philo = academy->list;
	cont = 0;
	id = 1;
	while (id <= academy->info.num_philos)
	{
		if (id % 2 == 0)
		{
			pid = fork();
			if (pid == 0)
				philosophers(philo);
			else
				academy->processes[cont] = pid;
		}
		id++;
		philo = philo->next;
		cont++;
	}
}

static void	set_odd_processes(t_academy *academy)
{
	t_philo		*philo;
	int			cont;
	int			id;
	int			pid;

	philo = academy->list;
	cont = 0;
	id = 1;
	while (id <= academy->info.num_philos)
	{
		if (id % 2 != 0)
		{
			pid = fork();
			if (pid == 0)
				philosophers(philo);
			else
				academy->processes[cont] = pid;
		}	
		id++;
		philo = philo->next;
		cont++;
	}
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
	unlink_sem();
	set_sems(academy);
	academy->list = NULL;
	set_list(academy);
	set_philo_lst_sems(&academy->list);
	academy->processes = malloc(sizeof(int) * academy->info.num_philos);
	academy->info.start_prog_milisec = get_miliseconds(academy->list);
	set_odd_processes(academy);
	set_even_processes(academy);
	wait(NULL);
	kill_processes(academy->processes, academy->info.num_philos);
	end_program(academy);
}
