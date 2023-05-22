/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:51:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/22 22:15:14 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



int	main(int ac, char **av)
{
	t_mlx	mlx;

	(void)ac;
	(void)av;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	if (!mlx.mlx_ptr)
		return (free(mlx.mlx_ptr), 1);
	hook_loop(&mlx);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
