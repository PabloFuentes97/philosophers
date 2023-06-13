/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:15:26 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	ft_usleep(t_philo *philo, unsigned long int rest)
{
	unsigned long int	time;
	unsigned long int	curr_time;

	time = get_miliseconds(philo);
	curr_time = time;
	while (curr_time < (rest + time))
	{
		usleep(500);
		curr_time = get_miliseconds(philo);
	}
	return (curr_time);
}

unsigned long int	get_miliseconds(t_philo *philo)
{
	unsigned long int	milisec;

	pthread_mutex_lock(philo->time);
	milisec = philo->info->time_struct.tv_sec * 1000
		+ philo->info->time_struct.tv_usec / 1000;
	pthread_mutex_unlock(philo->time);
	return (milisec);
}

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(philo->time);
	gettimeofday(&philo->info->time_struct, NULL);
	pthread_mutex_unlock(philo->time);
}

void	*time_check(void *academy)
{
	int					stop;
	t_academy			*academy_info;

	stop = 0;
	academy_info = (t_academy *)academy;
	set_time(academy_info->list);
	while (stop != 2)
	{
		set_time(academy_info->list);
		usleep(850);
		stop = get_stop(academy_info->list);
	}
	return (NULL);
}
