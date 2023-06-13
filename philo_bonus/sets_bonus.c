/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:07:34 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:07:39 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_state(t_philo *philo, int state)
{
	sem_wait(philo->sems_philo.state);
	philo->state = state;
	sem_post(philo->sems_philo.state);
}

void	set_wait_all_ate(t_philo *philo, int wait)
{
	sem_wait(philo->sems_philo.all_ate_checker);
	philo->wait_all_ate = wait;
	sem_post(philo->sems_philo.all_ate_checker);
}

void	set_last_eat(t_philo *philo, unsigned long int last_eat)
{
	sem_wait(philo->sems_philo.last_eat);
	philo->last_eat = last_eat;
	sem_post(philo->sems_philo.last_eat);
}
