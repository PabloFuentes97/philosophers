/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/08 12:22:04 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int id, t_academy *academy)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->info = &academy->info;
	philo->print_mutex = &academy->print_mutex;
	philo->stop = &academy->stop;
	philo->time = &academy->time;
	philo->all_eats = &academy->all_eats;
	philo->id = id;
	philo->state = 0;
	philo->fork = 0;
	pthread_mutex_init(&philo->fork_mutex, NULL);
	philo->num_eats = 0;
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}

t_philo	*ft_lstlast(t_philo *philos)
{
	if (!philos)
		return (NULL);
	while (philos->next != NULL)
	{
		philos = philos->next;
	}
	return (philos);
}

void	ft_lstadd_back(t_philo **philos, t_philo *new)
{
	t_philo	*last;

	last = ft_lstlast(*philos);
	if (!new)
		return ;
	if (philos)
	{
		if (*philos)
		{
			new->next = NULL;
			new->prev = last;
			if (last)
				last->next = new;
		}
		else
			*philos = new;
	}
}

void	ft_lstcircle(t_philo **philos, t_philo *new)
{
	if (!new)
		return ;
	if (philos)
	{
		if (*philos)
		{
			new->next = *philos;
			(*philos)->prev = new;
		}
		else
			*philos = new;
	}
}

t_philo	*ft_lstcirclelast(t_philo *philos)
{
	if (!philos)
		return (NULL);
	while (philos->next->id != 1)
	{
		philos = philos->next;
	}
	return (philos);
}
