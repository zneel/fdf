/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:52:57 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/29 09:23:30 by ebouvier         ###   ########.fr       */
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

# define MIN_WIDTH 1280
# define MIN_HEIGHT 720

typedef struct s_vect3
{
	int			x;
	int			y;
	int			z;
}				t_vect3;

typedef struct s_matrix
{
	int			**matrix;
	int			width;
	int			height;
	int			zoom;
	double		angle;
	int			tx;
	int			ty;
	int			min_z;
	int			max_z;
}				t_matrix;

typedef struct s_img
{
	void		*image;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
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

int				get_min(t_matrix *mat);
int				get_max(t_matrix *mat);
int				max(int a, int b);
int				min(int a, int b);
int				sign(int a, int b);

t_vect3			*get_vect3(t_matrix *mat, int x, int y);
void			draw_line(t_fdf *fdf, t_vect3 *start, t_vect3 *end);
void			calc_fdf(t_fdf *fdf);
void			put_pixel(t_img *data, int x, int y, int color);
void			draw_image(t_fdf *fdf);
t_img			*init_image(t_fdf *fdf);
t_vect3			*projection(t_fdf *fdf, t_vect3 *v3);
void			isometric(int *x, int *y, int z, double theta);

t_matrix		*create_matrix(void);
int				split_atoi(char *line, t_matrix *mat, int fd, int row);
int				get_matrix_dimensions(t_matrix *mat, char *file);
void			free_matrix(t_matrix *mat);
#endif