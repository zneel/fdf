/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:05:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/22 22:19:40 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	default_handler(void *mlx)
{
	(void)mlx;
	return (0);
}

int	key_handler(int k, t_mlx *mlx)
{
	if (k == XK_Escape || k == XK_q)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}