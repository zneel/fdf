/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:55:31 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/25 01:36:10 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

t_vect2	isometric_projection(t_matrix *mat, int x, int y)
{
	t_vect3	vect3;
	t_vect2	vect2;

	vect3.x = x;
	vect3.y = y;
	vect3.z = get_value_row_major_order(mat, vect3.x, vect3.y);
	vect2.x = sqrt(2) / 2 * (vect3.x - vect3.y);
	vect2.y = (sqrt(2 / 3) * vect3.z) - (1 / sqrt(6)) * (vect3.x + vect3.y);
	return (vect2);
}

void	bresenham(t_fdf *fdf, t_vect2 from, t_vect2 to)
{
	int	m_new;
	int	slope_error_new;

	m_new = 2 * (to.y - from.y);
	slope_error_new = m_new - (to.x - from.x);
	for (int x = from.x, y = from.y; x <= to.x; x++)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, rgb_encode(255, 255,
					255));
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (to.x - from.x);
		}
	}
}

void	draw_matrix(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdf->mat->size_x)
	{
		y = 0;
		while (y < fdf->mat->size_y)
		{
			if (x == fdf->mat->size_x - 1 && y + 1 < fdf->mat->size_y)
				bresenham(fdf, proj[x][y], proj[x][y + 1], offset_x, offset_y,
						scale);
			else if (y == fdf->mat->size_y - 1 && x != fdf->mat->size_x - 1)
				bresenham(fdf, proj[x][y], proj[x + 1][y], offset_x, offset_y,
						scale);
			else if (x < fdf->mat->size_x - 1 && y != fdf->mat->size_y)
			{
				bresenham(fdf, proj[x][y], proj[x][y + 1], offset_x, offset_y,
						scale);
				bresenham(fdf, proj[x][y], proj[x + 1][y], offset_x, offset_y,
						scale);
			}
			y++;
		}
		x++;
	}
	free_projection(fdf);
}
