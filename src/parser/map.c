/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:21:30 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/24 12:37:45 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_matrix_size(t_matrix *mat, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	mat->size_x = 0;
	mat->size_y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line && *line)
	{
		split = ft_split(line, ' ');
		if (!split)
			return (free(line));
		i = 0;
		mat->size_x++;
		while (split[i])
		{
			if (mat->size_x < 2 && ft_strncmp(split[i], "\n", 1) != 0)
				mat->size_y++;
			free(split[i]);
			i++;
		}
		free(split);
		free(line);
		line = get_next_line(fd);
	}
}

t_matrix	*open_map(char *file)
{
	int			fd;
	char		*line;
	t_matrix	*mat;
	char		**split;
	int			i;
	int			j;

	mat = malloc(sizeof(t_matrix));
	if (!mat)
		return (NULL);
	mat->matrix = NULL;
	init_matrix_size(mat, file);
    ft_printf("matx%d\n", mat->size_x);
    ft_printf("maty%d\n", mat->size_y);
    mat->matrix = malloc(sizeof(int) * (mat->size_x * mat->size_y));
	if (!mat->matrix)
		return (free(mat), NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(mat), NULL);
	line = get_next_line(fd);
    j = 0;
	while (line && *line)
	{
		split = ft_split(line, ' ');
		if (!split)
			return (free(line), free(mat->matrix), free(mat), NULL);
        i = 0;
		while (split[i])
		{
			if (ft_strncmp(split[i], "\n", 1) != 0)
				mat->matrix[j++] = ft_atoi(split[i]);
			free(split[i]);
			i++;
		}
		free(split);
		free(line);
		line = get_next_line(fd);
	}
	return (mat);
}
