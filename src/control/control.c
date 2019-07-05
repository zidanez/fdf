/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:10:24 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 21:16:07 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_hed.h"

void	move(int key, t_main **ptr)
{
	mlx_clear_window((*ptr)->mlx->mlx_ptr, (*ptr)->mlx->win_ptr);
	if (key == 126)
		(*ptr)->g_bais_y -= 10;
	if (key == 125)
		(*ptr)->g_bais_y += 10;
	if (key == 123)
		(*ptr)->g_bais_x -= 10;
	if (key == 124)
		(*ptr)->g_bais_x += 10;
	draw((*ptr));
}

void	zoom(int key, t_main **ptr)
{
	mlx_clear_window((*ptr)->mlx->mlx_ptr, (*ptr)->mlx->win_ptr);
	if (key == 47 && (*ptr)->zu < 4)
		(*ptr)->zu += (*ptr)->zu / 10;
	if (key == 43 && (*ptr)->zu > -4)
		(*ptr)->zu -= (*ptr)->zu / 10;
	if (key == 69 && (*ptr)->bais < 20)
	{
		(*ptr)->bais += (*ptr)->bais / 10;
		if ((*ptr)->zu > 0)
			(*ptr)->zu += (*ptr)->zu / 10;
		else
			(*ptr)->zu -= (*ptr)->zu / 10;
	}
	if (key == 78 && (*ptr)->bais > 1)
	{
		(*ptr)->bais -= (*ptr)->bais / 10;
		if ((*ptr)->zu > 0)
			(*ptr)->zu -= (*ptr)->zu / 10;
		else
			(*ptr)->zu += (*ptr)->zu / 10;
	}
	draw((*ptr));
}

void	rotate_key(int key, t_main **ptr)
{
	mlx_clear_window((*ptr)->mlx->mlx_ptr, (*ptr)->mlx->win_ptr);
	if (key == 83)
		(*ptr)->rotate = new_quatr(0, -1, 0, 0);
	else if (key == 86)
		(*ptr)->rotate = new_quatr(0, 1, 0, 0);
	else if (key == 84)
		(*ptr)->rotate = new_quatr(0, 0, -1, 0);
	else if (key == 87)
		(*ptr)->rotate = new_quatr(0, 0, 1, 0);
	else if (key == 85)
		(*ptr)->rotate = new_quatr(0, 0, 0, -1);
	else if (key == 88)
		(*ptr)->rotate = new_quatr(0, 0, 0, 1);
	(*ptr)->rotate = rotate(&(*ptr)->rotate, (*ptr)->angle);
	(*ptr)->q = multiply(&(*ptr)->q, &(*ptr)->rotate);
	draw((*ptr));
}

int		deal_key(int key, t_main **ptr)
{
	if (key == 126 || key == 123 || key == 125 || key == 124)
		move(key, &(*ptr));
	else if (key == 43 || key == 47 || key == 69 || key == 78)
		zoom(key, &(*ptr));
	else if (key == 86 || key == 87 || key == 88
	|| key == 83 || key == 84 || key == 85)
		rotate_key(key, &(*ptr));
	else if (key == 53)
		exit(0);
	return (0);
}
