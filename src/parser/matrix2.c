/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:15:43 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 11:02:01 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_both(char **split, char *line)
{
	free_split(split);
	free(line);
}

int	split_atoi(char *line, t_matrix *mat, int fd, int row)
{
	int		i;
	char	**split;

	split = ft_split(line, " \n");
	if (!split)
	{
		free(line);
		close(fd);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		mat->matrix[row][i] = ft_atoi(split[i]);
		i++;
	}
	free_both(split, line);
	return (1);
}
