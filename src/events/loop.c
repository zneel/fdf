/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:05:55 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/24 19:08:26 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hook_loop(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, KeyPress, KeyPressMask, key_handler, fdf);
	mlx_hook(fdf->win_ptr, ClientMessage, NoEventMask, close_handler, fdf);
	mlx_loop_hook(fdf->mlx_ptr, render, fdf);
	mlx_loop(fdf->mlx_ptr);
}