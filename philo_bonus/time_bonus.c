/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:10:44 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long int	get_miliseconds(t_philo	*philo)
{
	gettimeofday(&philo->time, NULL);
	return (philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, int sleep)
{
	unsigned long int	time;
	unsigned long int	curr;

	time = get_miliseconds(philo);
	curr = time;
	while (curr < (time + sleep))
	{
		usleep(250);
		curr = get_miliseconds(philo);
	}
}
