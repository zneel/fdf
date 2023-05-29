/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:11:19 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 11:31:27 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	split_count(t_matrix *mat, char *line, int fd)
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
		free(split[i++]);
	mat->height++;
	if (mat->height == 1)
		mat->width = i;
	else if (mat->height != 1 && i != mat->width)
		return (free(split), free(line), 0);
	return (free(split), free(line), 1);
}

int	get_matrix_dimensions(t_matrix *mat, char *file)
{
	int		fd;
	int		ok;
	int		has_err;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	has_err = 0;
	while (line && *line)
	{
		ok = split_count(mat, line, fd);
		if (!ok)
			has_err = 1;
		line = get_next_line(fd);
	}
	close(fd);
	if (has_err)
		return (free(line), 0);
	return (free(line), 1);
}

void	free_matrix(t_matrix *mat)
{
	int	row;

	if (!mat)
		return ;
	if (mat->matrix)
	{
		row = 0;
		while (row < mat->height)
			free(mat->matrix[row++]);
		free(mat->matrix);
	}
	free(mat);
}

t_matrix	*create_matrix(void)
{
	t_matrix	*mat;

	mat = malloc(sizeof(t_matrix));
	if (!mat)
		return (NULL);
	mat->width = 0;
	mat->height = 0;
	mat->matrix = NULL;
	return (mat);
}
