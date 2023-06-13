/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/05/26 11:47:45 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *philo)
{
	unsigned long	time;

	time = get_miliseconds(philo);
	pthread_mutex_lock(philo->print_mutex);
	if (philo->info->print == 0)
	{
		printf("%lu %d has died\n", time
			- philo->info->start_prog_milisec, philo->id);
		philo->info->print = 1;
	}
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_message(t_philo *philo, char *message)
{
	unsigned long	time;

	time = get_miliseconds(philo);
	pthread_mutex_lock(philo->print_mutex);
	if (philo->info->print == 0)
	{
		printf("%lu %d %s\n", time
			- philo->info->start_prog_milisec, philo->id, message);
	}
	pthread_mutex_unlock(philo->print_mutex);
}
