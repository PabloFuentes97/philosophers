/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/09 11:25:07 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_death(t_philo *philo)
{
	sem_wait(philo->sems->print);
	printf("%lu %d has died\n", get_miliseconds(philo)
		- philo->info->start_prog_milisec, philo->id);
}

void	print_message(t_philo *philo, char *message)
{
	sem_wait(philo->sems->print);
	printf("%lu %d %s\n", get_miliseconds(philo)
		- philo->info->start_prog_milisec, philo->id, message);
	sem_post(philo->sems->print);
}
