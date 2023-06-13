/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:14:26 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*get_fork(t_philo *p1, t_philo *p2, int num_fork)
{
	if (num_fork == 1)
	{
		if (p1->id % 2 == 0)
			return (p2);
		else
			return (p1);
	}
	else if (num_fork == 2)
	{
		if (p1->id % 2 == 0)
			return (p1);
		else
			return (p2);
	}
	return (NULL);
}

int	take_fork(t_philo *fork, t_philo *philo)
{
	int		taken;

	taken = 0;
	pthread_mutex_lock(&fork->fork_mutex);
	if (fork->fork == 0)
	{
		fork->fork = 1;
		taken = 1;
	}
	pthread_mutex_unlock(&fork->fork_mutex);
	if (taken == 1)
		print_message(philo, "has taken a fork");
	return (taken);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->fork_mutex);
}
