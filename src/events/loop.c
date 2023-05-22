/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:05:55 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/22 22:19:52 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hook_loop(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx_ptr, &default_handler, mlx);
	mlx_key_hook(mlx->win_ptr, &key_handler, mlx);
	mlx_loop(mlx->mlx_ptr);
}