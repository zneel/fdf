/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:51:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:49:41 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_mat(t_matrix *mat)
{
	int	i;

	i = 0;
	while (i < mat->height)
		free(mat->matrix[i++]);
	free(mat->matrix);
	free(mat);
}

void	exit_fdf(t_fdf *fdf)
{
	free(fdf->img);
	free_mat(fdf->mat);
	free(fdf->mlx_ptr);
}

void	init_struct(t_fdf *fdf)
{
	int	x;
	int	y;
	int	zoom_x;
	int	zoom_y;
	int	mini;

	x = fdf->mat->width;
	y = fdf->mat->height;
	fdf->mat->angle = -M_PI / 6;
	fdf->mat->min_z = get_min(fdf->mat);
	fdf->mat->max_z = get_max(fdf->mat);
	isometric(&x, &y, fdf->mat->max_z, fdf->mat->angle);
	fdf->img = init_image(fdf);
	zoom_x = (MIN_WIDTH / (1.75 * x));
	zoom_y = (MIN_HEIGHT / (1.75 * y));
	if (!zoom_x || !zoom_y)
	{
		zoom_x = 1;
		zoom_y = 1;
	}
	mini = min(abs(zoom_x), abs(zoom_y));
	fdf->mat->zoom = mini;
	fdf->mat->tx = (MIN_WIDTH - (x * fdf->mat->zoom)) / 2;
	fdf->mat->ty = (MIN_HEIGHT - (y * fdf->mat->zoom)) / 2;
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_printf("Error: missing map name\n"), 1);
	fdf.mat = open_map(av[1]);
	if (!fdf.mat)
		return (ft_printf("Error: cannot open map\n"), 1);
	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
		return (free(fdf.mat->matrix), free(fdf.mat), 1);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, MIN_WIDTH, MIN_HEIGHT, "fdf");
	if (!fdf.win_ptr)
		return (mlx_destroy_display(fdf.mlx_ptr), free(fdf.mlx_ptr), 1);
	init_struct(&fdf);
	calc_fdf(&fdf);
	hook_loop(&fdf);
	mlx_destroy_image(fdf.mlx_ptr, fdf.img->image);
	mlx_destroy_display(fdf.mlx_ptr);
	exit_fdf(&fdf);
	return (0);
}
