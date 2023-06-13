/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:14:13 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int_limits(char	**args)
{
	unsigned long long int	num;
	int						cont;

	cont = 0;
	while (args[cont])
	{
		num = ft_atoll(args[cont]);
		if (cont == 0)
		{
			if (num >= 1000)
				return (0);
		}
		if (num > 2147483647)
			return (0);
		cont++;
	}
	return (1);
}

int	check_death(t_philo *philo)
{
	unsigned long int	time;

	time = get_miliseconds(philo);
	if (time > (philo->info->time_to_die + philo->last_eat))
	{
		print_death(philo);
		set_stop(philo, 1, 0);
		return (1);
	}
	return (0);
}

void	rest_check(t_philo *philo, int rest, int state)
{
	unsigned long int	curr_mil;
	unsigned long int	time_to_rest;
	int					stop;

	curr_mil = get_miliseconds(philo);
	time_to_rest = curr_mil + (unsigned long int)rest;
	while (curr_mil < time_to_rest)
	{
		if (check_death(philo) == 1)
			break ;
		curr_mil = ft_usleep(philo, 1);
	}
	philo->state = state;
}
