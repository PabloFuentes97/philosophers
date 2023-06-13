/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:11:30 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_philo(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo, philo->info->time_to_sleep);
	set_state(philo, 0);
}

void	eat_philo(t_philo *philo)
{
	print_message(philo, "is eating");
	set_last_eat(philo, get_miliseconds(philo));
	philo->num_eats++;
	if (philo->num_eats == philo->info->num_eats)
	{
		set_wait_all_ate(philo, 1);
		sem_wait(philo->sems->all_ate);
		set_wait_all_ate(philo, 0);
	}
	ft_usleep(philo, philo->info->time_to_eat);
	sem_post(philo->sems->forks);
	sem_post(philo->sems->forks);
	set_state(philo, 2);
}

void	try_eat_philo(t_philo *philo)
{
	sem_wait(philo->sems->forks);
	print_message(philo, "has taken a fork");
	sem_wait(philo->sems->forks);
	print_message(philo, "has taken a fork");
	set_state(philo, 1);
}

void	think_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	try_eat_philo(philo);
}
