/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:11:50 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_checker(void *philo)
{
	t_philo	*philo_info;
	int		stop;
	int		state;
	int		check_all_ate;

	usleep(100);
	philo_info = (t_philo *)philo;
	stop = 0;
	check_all_ate = 0;
	while (stop == 0)
	{
		check_death(philo_info);
		state = get_state(philo);
		if (state == 1 && check_all_ate == 0)
		{
			all_ate_checker(philo_info);
			check_all_ate = 1;
		}
		else if (state != 1 && check_all_ate == 1)
			check_all_ate = 0;
		ft_usleep(philo_info, 1);
	}
	return (NULL);
}

void	*philosophers(t_philo *philo)
{
	int	stop;

	if (philo->id % 2 == 0)
		usleep(60);
	philo->last_eat = get_miliseconds(philo);
	pthread_create(&(philo->philo_checker), NULL,
		&philo_checker, (void *)philo);
	pthread_detach(philo->philo_checker);
	stop = 0;
	while (stop == 0)
	{
		if (philo->state == 0)
			think_philo(philo);
		else if (philo->state == 1)
			eat_philo(philo);
		else if (philo->state == 2)
			sleep_philo(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	char				**matrix;
	t_academy			philos;

	if (argc > 6)
		return (1);
	matrix = matrix_argv(argv);
	if (!matrix)
		return (1);
	set_academy(&philos, num_words(argv), matrix);
	return (0);
}
