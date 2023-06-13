/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/03/10 18:01:37 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	**set_matrix(char **matrix, char **argv, int words)
{
	int		row;
	int		cont_arg;
	int		cont_matrix;
	int		len;
	char	**arg;

	row = 1;
	cont_matrix = 0;
	cont_arg = 0;
	while (cont_matrix < words)
	{
		len = num_char(argv[row], ' ');
		arg = ft_split(argv[row], ' ');
		while (cont_arg < len)
		{
			matrix[cont_matrix] = arg[cont_arg];
			cont_matrix++;
			cont_arg++;
		}
		free(arg);
		row++;
		cont_arg = 0;
	}
	matrix[cont_matrix] = NULL;
	return (matrix);
}

static int	check_num_spaces(char **matrix)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (matrix[row])
	{
		while (matrix[row][col])
		{
			if ((matrix[row][col] >= '0' && matrix[row][col] <= '9')
				|| matrix[row][col] == ' ')
				col++;
			else
				return (0);
		}
		row++;
		col = 0;
	}
	return (1);
}

char	**matrix_argv(char **argv)
{
	int		words;
	char	**matrix;

	if (check_num_spaces(argv) == 0)
		return (NULL);
	words = num_words(argv);
	if (words < 4 || words > 5)
		return (NULL);
	matrix = malloc(sizeof(char *) * words + 1);
	matrix = set_matrix(matrix, argv, words);
	return (matrix);
}
