/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:10:24 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/27 11:11:31 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		if (pixel >= img->addr && pixel + sizeof(color) <= img->addr + (W_HEIGHT
				* img->line_len + W_WIDTH * (img->bpp / 8)))
		{
			*(int *)pixel = color;
		}
	}
}

void	*init_image(t_fdf *fdf)
{
	fdf->img = malloc(sizeof(t_img));
	if (!fdf->img)
		return (NULL);
	fdf->img->bpp = 0;
	fdf->img->line_len = 0;
	fdf->img->endian = 0;
	fdf->img->image = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->image, &fdf->img->bpp,
			&fdf->img->line_len, &fdf->img->endian);
	return (fdf->img);
}

void	draw_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->image, 0, 0);
}