/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/03/07 11:45:57 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	num_char(char const *s, char c)
{
	int		cont;
	int		len;

	cont = 0;
	len = 0;
	while (s[cont] == c && s[cont])
			cont++;
	while (s[cont])
	{
		len++;
		while (s[cont] != c && s[cont])
			cont++;
		while (s[cont] == c && s[cont])
			cont++;
	}
	return (len);
}

int	num_words(char **argv)
{
	int	words;
	int	row;

	words = 0;
	row = 1;
	while (argv[row])
	{
		words += num_char(argv[row], ' ');
		row++;
	}
	return (words);
}

void	free_matrix(char **matrix)
{
	int	cont;

	cont = 0;
	if (matrix)
	{
		while (matrix[cont])
		{
			free(matrix[cont]);
			cont++;
		}
		free(matrix);
	}
	matrix = NULL;
}
