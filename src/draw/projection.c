/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:03:21 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:04:03 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Apply isometric projection to the given coordinates.
 *
 * @param x Pointer to the x-coordinate to be transformed.
 * @param y Pointer to the y-coordinate to be transformed.
 * @param z The z-coordinate to be transformed.
 * @param theta The angle of rotation for the projection.
 */
void	isometric(int *x, int *y, int z, double theta)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x + tmp_y) * cos(theta);
	*y = (tmp_x - tmp_y) * sin(theta) - z;
}

t_vect3	*projection(t_fdf *fdf, t_vect3 *v3)
{
	v3->x *= fdf->mat->zoom;
	v3->y *= fdf->mat->zoom;
	v3->z *= fdf->mat->zoom;
	isometric(&v3->x, &v3->y, v3->z, fdf->mat->angle);
	v3->x += fdf->mat->tx;
	v3->y += fdf->mat->ty;
	return (v3);
}
