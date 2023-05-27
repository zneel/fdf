/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:55:31 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/27 11:08:38 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	isometric(int *x, int *y, int z, double theta)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(theta);
	*y = (tmp_x + tmp_y) * sin(theta) - z;
}

t_vect3	*projection(t_fdf *fdf, t_vect3 *v3)
{
	v3->x *= fdf->mat->zoom;
	v3->y *= -fdf->mat->zoom;
	v3->z *= fdf->mat->zoom;
	isometric(&v3->x, &v3->y, v3->z, fdf->mat->angle);
	v3->x += fdf->mat->tx;
	v3->y += fdf->mat->ty;
	return (v3);
}

int	sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
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

int	get_color(int z)
{
	if (z < 0)
		return (0x00b7ff);
	else if (z > 0)
		return (0xcc0000);
	else
		return (0xffffff);
}

void	draw_line(t_fdf *fdf, t_vect3 *start, t_vect3 *end)
{
	t_bren	b;

	init_bresenham(&b, start, end);
	while (start->x != end->x || start->y != end->y)
	{
		put_pixel(fdf->img, start->x, start->y, get_color(start->z));
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

t_vect3	*get_vect3(t_matrix *mat, int x, int y)
{
	t_vect3	*v3;

	v3 = malloc(sizeof(t_vect3));
	if (!v3)
		return (NULL);
	v3->x = x;
	v3->y = y;
	v3->z = get_value_row_major_order(mat, x, y);
	return (v3);
}

void	trace(t_fdf *fdf, int x, int y)
{
	t_vect3	*start;
	t_vect3	*end;

	if (x < fdf->mat->width - 1)
	{
		start = projection(fdf, get_vect3(fdf->mat, x, y));
		end = projection(fdf, get_vect3(fdf->mat, x + 1, y));
		draw_line(fdf, start, end);
		free(start);
		free(end);
	}
	if (y < fdf->mat->height - 1)
	{
		start = projection(fdf, get_vect3(fdf->mat, x, y));
		end = projection(fdf, get_vect3(fdf->mat, x, y + 1));
		draw_line(fdf, start, end);
		free(start);
		free(end);
	}
}

void	draw_matrix(t_fdf *fdf)
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
