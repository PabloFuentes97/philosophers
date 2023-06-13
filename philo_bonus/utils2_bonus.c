/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/03/21 16:24:19 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	int		cont_s;
	int		cont_join;

	if (!s1 || !s2)
		return (0);
	array = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (array == NULL)
		return (NULL);
	cont_s = 0;
	cont_join = 0;
	while (s1[cont_join] != '\0')
	{
		array[cont_join] = s1[cont_join];
		cont_join++;
	}
	while (s2[cont_s] != '\0')
	{
		array[cont_join] = s2[cont_s];
		cont_join++;
		cont_s++;
	}
	array[cont_join] = '\0';
	return (array);
}
