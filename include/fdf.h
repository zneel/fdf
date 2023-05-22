/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:52:57 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/22 22:19:50 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>

# define W_WIDTH 1280
# define W_HEIGHT 720

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

int			default_handler(void *mlx);
int			key_handler(int k, t_mlx *mlx);
void		hook_loop(t_mlx *mlx);

#endif