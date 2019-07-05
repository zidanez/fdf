/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:11:36 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 21:12:11 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_hed.h"

int			get_bais(int x_size, int y_size)
{
	int		x;

	x = x_size > y_size ? x_size : y_size;
	if (x >= 500)
		return (2);
	if (x >= 100)
		return (5);
	else
		return (10);
}

t_dot		*get_dot(int x, int y, int z)
{
	t_dot	*new_dot;

	if (!(new_dot = (t_dot*)malloc(sizeof(t_dot))))
	{
		ft_putstr(" Can't malloc new dot\n");
		exit(0);
	}
	else
	{
		new_dot->x = x;
		new_dot->y = y;
		new_dot->z = z;
		return (new_dot);
	}
}

t_line		*get_line(t_dot *one, t_dot *two, t_mlx *mlx)
{
	t_line	*new_line;

	if (!(new_line = (t_line*)malloc(sizeof(t_line))))
	{
		ft_putstr(" Can't malloc new line\n");
		exit(0);
	}
	else
	{
		new_line->one = one;
		new_line->two = two;
		new_line->mlx = mlx;
		return (new_line);
	}
}

t_dot		*init_prev(void)
{
	t_dot	*new;

	if (!(new = (t_dot *)malloc(sizeof(t_dot))))
	{
		ft_putstr(" Can't malloc prev dot\n");
		exit(0);
	}
	else
	{
		new->x = 0;
		new->y = 0;
		new->z = 0;
		return (new);
	}
}

t_main		*init_ptr(void *mlx_ptr, void *win_ptr, char *file)
{
	t_main	*main_p;

	if (!(main_p = (t_main*)malloc(sizeof(t_main))))
	{
		ft_putstr(" Can't malloc t_main\n");
		exit(0);
	}
	main_p->map = read_f(file);
	if (!(main_p->mlx = (t_mlx*)malloc(sizeof(t_mlx))))
	{
		ft_putstr(" Can't malloc t_mlx\n");
		exit(0);
	}
	main_p->mlx->mlx_ptr = mlx_ptr;
	main_p->mlx->win_ptr = win_ptr;
	main_p->angle = 10;
	main_p->q = new_quatr(1, 0, 0, 0);
	main_p->bais = get_bais(main_p->map->x_c, main_p->map->y_c);
	main_p->zu = main_p->bais / 10;
	main_p->g_bais_y = (WIN_H / 2);
	main_p->g_bais_x = (WIN_W / 2);
	main_p->prev = init_prev();
	main_p->l_b_m = 0;
	main_p->r_b_m = 0;
	return (main_p);
}
