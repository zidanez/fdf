/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:24:53 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 20:06:30 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_hed.h"
#include "../../include/quaternion.h"

void			put_line(float x_delta, float y_delta, t_line **line)
{
	int			i;
	float		k;

	i = 0;
	if (fabsf(x_delta) >= fabsf(y_delta))
	{
		k = y_delta / x_delta;
		while (x_delta != i)
		{
			mlx_pixel_put((*line)->mlx->mlx_ptr, (*line)->mlx->win_ptr,
					i + (*line)->one->x, i * k + (*line)->one->y, WHITE);
			x_delta > 0 ? ++i : --i;
		}
	}
	else
	{
		k = x_delta / y_delta;
		while (y_delta != i)
		{
			mlx_pixel_put((*line)->mlx->mlx_ptr, (*line)->mlx->win_ptr,
					i * k + (*line)->one->x, i + (*line)->one->y, WHITE);
			y_delta > 0 ? ++i : --i;
		}
	}
	free_line(&(*line));
}

void			draw_line(t_line **line)
{
	float		x_delta;
	float		y_delta;

	x_delta = (*line)->two->x - (*line)->one->x;
	y_delta = (*line)->two->y - (*line)->one->y;
	put_line(x_delta, y_delta, &(*line));
}

void			draw_map(int x, int y, t_main *ptr)
{
	int			next_x;
	int			next_y;
	t_dot		n;
	t_dot		n1;
	t_line		*line;

	next_x = x + 1 < ptr->map->x_c ? x + 1 : x;
	next_y = y + 1 < ptr->map->y_c ? y + 1 : y;
	n = init_rotate(&ptr, x, y, ptr->map->map[y][x]);
	n1 = init_rotate(&ptr, next_x, y, ptr->map->map[y][next_x]);
	line = get_line(get_dot((n.x * ptr->bais) - (n.z * ptr->zu) + ptr->g_bais_x,
			(n.y * ptr->bais) + (n.z * ptr->zu) + ptr->g_bais_y,
			ptr->map->map[y][x]),
		get_dot((n1.x * ptr->bais) - (n1.z * ptr->zu) + ptr->g_bais_x,
			(n1.y * ptr->bais) + (n1.z * ptr->zu) + ptr->g_bais_y,
			ptr->map->map[y][next_x]), ptr->mlx);
	draw_line(&line);
	n1 = init_rotate(&ptr, x, next_y, ptr->map->map[next_y][x]);
	line = get_line(get_dot((n.x * ptr->bais) - (n.z * ptr->zu) + ptr->g_bais_x,
			(n.y * ptr->bais) + (n.z * ptr->zu) + ptr->g_bais_y,
			ptr->map->map[y][x]),
		get_dot((n1.x * ptr->bais) - (n1.z * ptr->zu) + ptr->g_bais_x,
			(n1.y * ptr->bais) + (n1.z * ptr->zu) + ptr->g_bais_y,
			ptr->map->map[next_y][x]), ptr->mlx);
	draw_line(&line);
}

void			draw(t_main *ptr)
{
	int			x;
	int			y;
	int			bais;

	y = -1;
	while (++y < ptr->map->y_c)
	{
		x = -1;
		while (++x < ptr->map->x_c)
			draw_map(x, y, ptr);
	}
}
