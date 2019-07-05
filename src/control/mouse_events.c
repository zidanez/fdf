/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:15:29 by fnancy            #+#    #+#             */
/*   Updated: 2019/06/18 14:52:00 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_hed.h"

int		close_win(void *param)
{
	exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_main **ptr)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom(78, &(*ptr));
		else
			zoom(69, &(*ptr));
		return (2);
	}
	if (button == 1)
		(*ptr)->l_b_m = 1;
	if (button == 2)
		(*ptr)->r_b_m = 1;
	(*ptr)->prev->x = 0;
	(*ptr)->prev->y = 0;
	(*ptr)->prev->z = 0;
	return (1);
}

int		mouse_release(int button, int x, int y, t_main **ptr)
{
	if (button == 1)
		(*ptr)->l_b_m = 0;
	if (button == 2)
		(*ptr)->r_b_m = 0;
	return (1);
}

void	draw_rotate(t_main **ptr)
{
	if ((*ptr)->rotate)
	{
		(*ptr)->rotate = rotate(&(*ptr)->rotate, (*ptr)->angle);
		quatr_normalize(&(*ptr)->rotate);
		(*ptr)->q = multiply(&(*ptr)->q, &(*ptr)->rotate);
		mlx_clear_window((*ptr)->mlx->mlx_ptr, (*ptr)->mlx->win_ptr);
		draw((*ptr));
	}
}

int		mouse_move(int x, int y, t_main **ptr)
{
	if ((*ptr)->l_b_m == 1)
	{
		if ((*ptr)->r_b_m == 1)
		{
			if (((*ptr)->prev->x) - x > 1)
				(*ptr)->rotate = new_quatr(0, 0, 0, 1);
			else if (((*ptr)->prev->x) - x < -1)
				(*ptr)->rotate = new_quatr(0, 0, 0, -1);
		}
		else
		{
			if (((*ptr)->prev->y) - y > 1)
				(*ptr)->rotate = new_quatr(0, 1, 0, 0);
			else if (((*ptr)->prev->y) - y < -1)
				(*ptr)->rotate = new_quatr(0, -1, 0, 0);
			else if (((*ptr)->prev->x) - x > 1)
				(*ptr)->rotate = new_quatr(0, 0, 1, 0);
			else if (((*ptr)->prev->x) - x < -1)
				(*ptr)->rotate = new_quatr(0, 0, -1, 0);
		}
		(*ptr)->prev->x = x;
		(*ptr)->prev->y = y;
		draw_rotate(&(*ptr));
	}
	return (0);
}
