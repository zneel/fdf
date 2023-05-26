/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:05:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/26 22:57:11 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_handler(int k, t_fdf *fdf)
{
	if (k == XK_Escape || k == XK_q)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->win_ptr = NULL;
	}
	return (0);
}

int	close_handler(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->win_ptr = NULL;
	return (0);
}

int	render(t_fdf *fdf)
{
	if (fdf && fdf->win_ptr && fdf->mlx_ptr)
	{
		draw_matrix(fdf);
		draw_image(fdf);
	}
	return (0);
}
