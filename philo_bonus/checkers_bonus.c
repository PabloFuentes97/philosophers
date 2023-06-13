/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:12:17 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	check_death(t_philo *philo)
{
	unsigned long int	last_eat;

	if ((get_miliseconds(philo) > (philo->info->time_to_die
				+ get_last_eat(philo))))
	{
		print_death(philo);
		exit(0);
	}
}

void	all_ate_checker(t_philo *philo)
{
	int	wait;

	usleep(100);
	wait = get_wait_all_ate(philo);
	if (wait == 1)
		exit(1);
}
