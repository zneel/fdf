/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:10:24 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:00:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		if (pixel >= img->addr && pixel + sizeof(color) <= img->addr
			+ (img->height * img->line_len + img->width * (img->bpp / 8)))
		{
			*(int *)pixel = color;
		}
	}
}

t_img	*init_image(t_fdf *fdf)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = MIN_WIDTH;
	img->height = MIN_HEIGHT;
	img->image = mlx_new_image(fdf->mlx_ptr, img->width, img->height);
	img->addr = mlx_get_data_addr(img->image, &img->bpp, &img->line_len,
			&img->endian);
	return (img);
}

void	draw_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->image, 0, 0);
}
