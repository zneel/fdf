/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:07:26 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Compute the color based on the given z-value.
 *
 * @param fdf Pointer to the t_fdf structure.
 * @param z The z-value for which to compute the color.
 * @return The computed color as an integer value.
 */
int	compute_color(t_fdf *fdf, int z)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)(z - fdf->mat->min_z) / (fdf->mat->max_z - fdf->mat->min_z);
	r = 0;
	if (z >= 0)
	{
		g = 50 + (int)(205 * t);
		b = 100 + (int)(155 * t);
	}
	else
	{
		g = 50 + (int)(205 * (1 + t));
		b = 100 + (int)(55 * (1 + t));
	}
	return ((r << 16) | (g << 8) | b);
}

void	init_bresenham(t_bren *b, t_vect3 *start, t_vect3 *end)
{
	b->dx = abs(end->x - start->x);
	b->sx = sign(start->x, end->x);
	b->dy = abs(end->y - start->y);
	b->sy = sign(start->y, end->y);
	if (b->dx > b->dy)
		b->err = b->dx / 2;
	else
		b->err = -b->dy / 2;
}

/**
 * @brief Draw a line between two 3D points using Bresenham's line algorithm.
 *
 * @param fdf Pointer to the t_fdf structure.
 * @param start Pointer to the starting point of the line.
 * @param end Pointer to the ending point of the line.
 */
void	draw_line(t_fdf *fdf, t_vect3 *start, t_vect3 *end)
{
	t_bren	b;
	int		color;

	init_bresenham(&b, start, end);
	while (start->x != end->x || start->y != end->y)
	{
		color = compute_color(fdf, start->z);
		put_pixel(fdf->img, start->x, start->y, color);
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			start->x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			start->y += b.sy;
		}
	}
}
