/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:07:52 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_state(t_philo	*philo)
{
	int	state;

	sem_wait(philo->sems_philo.state);
	state = philo->state;
	sem_post(philo->sems_philo.state);
	return (state);
}

int	get_wait_all_ate(t_philo *philo)
{
	int	wait;

	sem_wait(philo->sems_philo.all_ate_checker);
	wait = philo->wait_all_ate;
	sem_post(philo->sems_philo.all_ate_checker);
	return (wait);
}

unsigned long int	get_last_eat(t_philo *philo)
{
	unsigned long int	last_eat;

	sem_wait(philo->sems_philo.last_eat);
	last_eat = philo->last_eat;
	sem_post(philo->sems_philo.last_eat);
	return (last_eat);
}
