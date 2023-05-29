/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:55:31 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:07:39 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	trace(t_fdf *fdf, int x, int y)
{
	t_vect3	*start;
	t_vect3	*end;

	if (y < fdf->mat->height - 1)
	{
		start = projection(fdf, get_vect3(fdf->mat, x, y));
		end = projection(fdf, get_vect3(fdf->mat, x, y + 1));
		draw_line(fdf, start, end);
		free(start);
		free(end);
	}
	if (x < fdf->mat->width - 1)
	{
		start = projection(fdf, get_vect3(fdf->mat, x, y));
		end = projection(fdf, get_vect3(fdf->mat, x + 1, y));
		draw_line(fdf, start, end);
		free(start);
		free(end);
	}
}

/**
 * @brief Calculate the FDF representation by tracing each point in the matrix.
 *
 * @param fdf Pointer to the t_fdf structure.
 */
void	calc_fdf(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->mat->height)
	{
		x = 0;
		while (x < fdf->mat->width)
		{
			trace(fdf, x, y);
			x++;
		}
		y++;
	}
}
