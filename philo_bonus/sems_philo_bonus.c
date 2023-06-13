/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 11:54:35 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	set_philo_sems(t_philo **philo)
{
	char	*id;
	t_philo	*curr;

	curr = *philo;
	id = ft_itoa(curr->id);
	curr->sems_philo.all_ate_checker_name = ft_strjoin("/all_ate_checker",
			id);
	sem_unlink(curr->sems_philo.all_ate_checker_name);
	curr->sems_philo.all_ate_checker = sem_open(
			curr->sems_philo.all_ate_checker_name, O_CREAT, 0644, 1);
	curr->sems_philo.state_name = ft_strjoin("/state", id);
	sem_unlink(curr->sems_philo.state_name);
	curr->sems_philo.state = sem_open(curr->sems_philo.state_name,
			O_CREAT, 0644, 1);
	curr->sems_philo.last_eat_name = ft_strjoin("/last_eat", id);
	sem_unlink(curr->sems_philo.last_eat_name);
	curr->sems_philo.last_eat = sem_open(curr->sems_philo.last_eat_name,
			O_CREAT, 0644, 1);
	free(id);
}

void	set_philo_lst_sems(t_philo	**philo)
{
	t_philo	*curr;
	int		cont;

	curr = *philo;
	cont = 0;
	while (cont < curr->info->num_philos)
	{
		set_philo_sems(&curr);
		curr = curr->next;
		cont++;
	}
}

static void	free_philo_sems(t_philo **philo)
{
	t_philo	*curr;

	curr = *philo;
	sem_close(curr->sems_philo.all_ate_checker);
	sem_unlink(curr->sems_philo.all_ate_checker_name);
	free(curr->sems_philo.all_ate_checker_name);
	sem_close(curr->sems_philo.state);
	sem_unlink(curr->sems_philo.state_name);
	free(curr->sems_philo.state_name);
	sem_close(curr->sems_philo.last_eat);
	sem_unlink(curr->sems_philo.last_eat_name);
	free(curr->sems_philo.last_eat_name);
}

void	free_philo_lst_sems(t_philo	**philo)
{
	t_philo	*curr;
	int		cont;

	curr = *philo;
	cont = 0;
	while (cont < curr->info->num_philos)
	{
		free_philo_sems(&curr);
		curr = curr->next;
		cont++;
	}
}
