/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/03/21 17:23:51 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_sem(t_academy *academy)
{
	sem_close(academy->sems.print);
	sem_close(academy->sems.forks);
	sem_close(academy->sems.all_ate);
}

void	unlink_sem(void)
{
	sem_unlink("/print");
	sem_unlink("/forks");
	sem_unlink("/all_ate");
}

void	set_sems(t_academy *academy)
{
	academy->sems.print = sem_open("/print", O_CREAT, 0644, 1);
	academy->sems.all_ate = sem_open("/all_ate", O_CREAT, 0644,
			academy->info.num_philos - 1);
	academy->sems.forks = sem_open("/forks", O_CREAT, 0644,
			academy->info.num_philos);
}
