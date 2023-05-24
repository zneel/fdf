/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:51:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/24 19:06:55 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_fdf(t_fdf *fdf)
{
	free(fdf->mat->matrix);
	free(fdf->mat);
	free(fdf->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_fdf		fdf;

	if (ac != 2)
		return (ft_printf("Error: missing map name\n"), 1);
	fdf.mat = open_map(av[1]);
	if (!fdf.mat)
		return (ft_printf("Error: cannot open map\n"), 1);
	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
		return (free(fdf.mat->matrix), free(fdf.mat), 1);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	if (!fdf.win_ptr)
		return (mlx_destroy_display(fdf.mlx_ptr), free(fdf.mlx_ptr), 1);
	draw_matrix(&fdf);
	hook_loop(&fdf);
	mlx_destroy_display(fdf.mlx_ptr);
	exit_fdf(&fdf);
	return (0);
}
