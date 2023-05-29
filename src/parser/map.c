/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:21:30 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 11:27:16 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	populate_matrix(t_matrix *mat, char *file)
{
	int		fd;
	int		ok;
	char	*line;
	int		row;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	row = 0;
	ok = 0;
	while (line && *line)
	{
		ok = split_atoi(line, mat, fd, row);
		if (!ok)
			break ;
		line = get_next_line(fd);
		row++;
	}
	close(fd);
	free(line);
	if (!ok)
		return (0);
	return (1);
}

int	alloc_matrix(t_matrix *mat)
{
	int	row;
	int	i;

	mat->matrix = malloc(sizeof(int *) * mat->height);
	if (!mat->matrix)
		return (0);
	row = 0;
	while (row < mat->height)
	{
		mat->matrix[row] = malloc(sizeof(int) * mat->width);
		if (!mat->matrix[row])
		{
			i = 0;
			while (i < row)
			{
				free(mat->matrix[i]);
				i++;
			}
			free(mat->matrix);
			return (0);
		}
		row++;
	}
	return (1);
}

t_matrix	*open_map(char *file)
{
	t_matrix	*mat;

	mat = create_matrix();
	if (!mat)
		return (NULL);
	if (!get_matrix_dimensions(mat, file))
		return (free_matrix(mat), NULL);
	if (!alloc_matrix(mat))
		return (free_matrix(mat), NULL);
	if (!populate_matrix(mat, file))
		return (free_matrix(mat), NULL);
	return (mat);
}
