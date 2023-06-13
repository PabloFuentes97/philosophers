/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:03:20 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophers(void *philo_data)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)philo_data;
	if (philo->id % 2 == 0)
	{
		if (philo->info->num_philos > 70)
			usleep(philo->info->num_philos * 1.4);
		else
			usleep(60);
	}
	philo->last_eat = get_miliseconds(philo);
	stop = 0;
	while (stop == 0)
	{
		if (philo->state == 0)
			think_philo(philo);
		else if (philo->state == 1)
			eat_philo(philo);
		else if (philo->state == 2)
			sleep_philo(philo);
		stop = get_stop(philo);
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
