/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:14:52 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_philo(t_philo *philo)
{
	print_message(philo, "is sleeping");
	rest_check(philo, philo->info->time_to_sleep, 0);
}

void	eat_philo(t_philo *philo)
{
	philo->last_eat = get_miliseconds(philo);
	philo->num_eats++;
	if (philo->num_eats == philo->info->num_eats)
		set_all_eats(philo);
	print_message(philo, "is eating");
	rest_check(philo, philo->info->time_to_eat, 2);
	release_fork(philo);
	release_fork(philo->next);
}

void	try_eat_philo(t_philo *philo)
{
	int					forks[2];
	t_philo				*fork1;
	t_philo				*fork2;

	forks[0] = 0;
	forks[1] = 0;
	fork1 = get_fork(philo, philo->next, 1);
	fork2 = get_fork(philo, philo->next, 2);
	while (forks[0] == 0 || forks[1] == 0)
	{
		if (forks[0] == 0)
			forks[0] = take_fork(fork1, philo);
		if (forks[1] == 0)
			forks[1] = take_fork(fork2, philo);
		if (check_death(philo) == 1)
			break ;
	}
	philo->state = 1;
}

void	think_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	try_eat_philo(philo);
}
