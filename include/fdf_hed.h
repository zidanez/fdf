/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hed.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:28:22 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 19:55:18 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HED_H
# define FDF_HED_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "quaternion.h"

# define WHITE 0xffffff
# define RED 0xff00000
# define WIN_W 1500
# define WIN_H 1000

typedef struct	s_dot
{
	float		x;
	float		y;
	float		z;
}				t_dot;

typedef struct	s_mas
{
	float		x_c;
	float		y_c;
	int			**map;
}				t_mas;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_ptr
{
	t_mlx		*mlx;
	t_mas		*map;
	float		zu;
	float		bais;
	int			g_bais_y;
	int			g_bais_x;
	int			angle;
	t_quatr		*rotate;
	t_quatr		*q;
	t_dot		*prev;
	int			l_b_m;
	int			r_b_m;
}				t_main;

typedef struct	s_line
{
	t_dot		*one;
	t_dot		*two;
	t_mlx		*mlx;
}				t_line;

t_mas			*read_f(char *file);
t_main			*init_ptr(void *mlx_ptr, void *win_ptr, char *file);
int				deal_key(int key, t_main **param);
int				get_next_line(const int fd, char **line);
void			draw_line(t_line **line);
void			draw(t_main *ptr);
t_line			*get_line(t_dot *one, t_dot *two, t_mlx *mlx);
t_dot			*get_dot(int x, int y, int z);
void			free_line(t_line **line);
void			draw(t_main *ptr);
t_dot			init_rotate(t_main **ptr, int x, int y, int z);
void			zoom(int key, t_main **ptr);
int				close_win(void *param);
int				mouse_move(int x, int y, t_main **ptr);
int				mouse_release(int button, int x, int y, t_main **ptr);
int				mouse_press(int button, int x, int y, t_main **ptr);
void			init_columns_mas(t_mas **res);
int				validate_map(t_mas **res, int fd);

#endif
