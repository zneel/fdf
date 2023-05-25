/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:52:57 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/25 23:06:38 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <sys/stat.h>
# include <sys/types.h>

# define W_WIDTH 1280
# define W_HEIGHT 720

typedef struct s_vect3
{
	int			x;
	int			y;
	int			z;
}				t_vect3;

typedef struct s_matrix
{
	int			*matrix;
	int			width;
	int			height;
	int			zoom;
	double		angle;
	int			tx;
	int			ty;
}				t_matrix;

typedef struct s_img
{
	void		*image;
	char		*data;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	*mat;
	t_img		*img;
}				t_fdf;

typedef struct s_bren
{
	int			dx;
	int			dy;
	int			err;
	int			e2;
	int			sx;
	int			sy;
}				t_bren;

t_matrix		*open_map(char *file);

int				key_handler(int k, t_fdf *fdf);
int				close_handler(t_fdf *fdf);

int				render(t_fdf *fdf);
void			hook_loop(t_fdf *fdf);

int				rgb_encode(uint8_t r, uint8_t g, uint8_t b);
int				get_value_row_major_order(t_matrix *matrix, int x, int y);

void			draw_matrix(t_fdf *fdf);

#endif