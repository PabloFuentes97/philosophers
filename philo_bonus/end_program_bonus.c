/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/03/23 13:28:05 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_circle_list(t_philo **head, int num)
{
	t_philo	*curr;
	t_philo	*next;
	int		cont;

	if (head)
	{
		if (*head)
		{
			curr = *head;
			cont = 0;
			while (cont < num)
			{
				next = (curr)->next;
				curr->next = NULL;
				free(curr);
				curr = next;
				cont++;
			}
		}
	}
	head = NULL;
}

void	kill_processes(int	*processes_pid, int num_processes)
{
	int	cont;

	cont = 0;
	while (cont < num_processes)
	{
		kill(processes_pid[cont], SIGKILL);
		cont++;
	}
}

void	end_program(t_academy *academy)
{
	t_philo	*philo;

	philo = academy->list;
	free(academy->processes);
	free_philo_lst_sems(&academy->list);
	free_circle_list(&academy->list, academy->info.num_philos);
	close_sem(academy);
	unlink_sem();
}
