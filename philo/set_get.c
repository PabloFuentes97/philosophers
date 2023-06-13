/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 11:38:51 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop(t_philo *philo, int value, int mode)
{
	pthread_mutex_lock(philo->stop);
	philo->info->stop = value;
	pthread_mutex_unlock(philo->stop);
	if (mode == 1)
	{
		pthread_mutex_lock(philo->print_mutex);
		philo->info->print = 1;
		pthread_mutex_unlock(philo->print_mutex);
	}
}

int	get_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(philo->stop);
	stop = philo->info->stop;
	pthread_mutex_unlock(philo->stop);
	return (stop);
}

void	set_all_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->all_eats);
	philo->info->all_ate++;
	if (philo->info->all_ate == philo->info->num_philos)
	{
		set_stop(philo, 1, 1);
		pthread_mutex_unlock(philo->all_eats);
	}
	else
		pthread_mutex_unlock(philo->all_eats);
}
