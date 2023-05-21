/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:51:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 22:21:25 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

    (void)ac;
    (void)av;
	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_new_window(mlx, 1280, 720, "fdf");
	mlx_loop(mlx);
    return (0);
}