/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 11:30:18 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_circle_list(t_philo **head, int num)
{
	t_philo	*curr;
	t_philo	*next;
	int		cont;

	if (!head || !*head)
		return ;
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
	*head = NULL;
	head = NULL;
}

void	end_program(t_academy *academy)
{
	int		cont;
	t_philo	*philo;

	printf("Terminar programa\n");
	cont = 0;
	philo = academy->list;
	while (cont < academy->info.num_philos)
	{
		pthread_mutex_destroy(&philo->fork_mutex);
		philo = philo->next;
		cont++;
	}
	free(academy->threads);
	free_circle_list(&academy->list, academy->info.num_philos);
	pthread_mutex_destroy(&academy->print_mutex);
	pthread_mutex_destroy(&academy->stop);
	pthread_mutex_destroy(&academy->all_eats);
	pthread_mutex_destroy(&academy->time);
	printf("Destruyó todo\n");
}
