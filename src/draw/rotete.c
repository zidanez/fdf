/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:47:41 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 20:04:52 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_hed.h"
#include "../../include/quaternion.h"

float		get_x(t_quatr *q, int x, int y, int z)
{
	return ((1 - 2 * pow(q->y, 2) - 2 * pow(q->z, 2)) * x
	+ (2 * q->x * q->y - 2 * q->w * q->z) * y
	+ (2 * q->x * q->z + 2 * q->w * q->y) * z);
}

float		get_y(t_quatr *q, int x, int y, int z)
{
	return ((2 * q->x * q->y + 2 * q->w * q->z) * x
	+ (1 - 2 * pow(q->x, 2) - 2 * pow(q->z, 2)) * y
	+ (2 * q->y * q->z - 2 * q->w * q->x) * z);
}

float		get_z(t_quatr *q, int x, int y, int z)
{
	return ((2 * q->x * q->z - 2 * q->w * q->y) * x
	+ (2 * q->y * q->z + 2 * q->w * q->x) * y
	+ (1 - 2 * pow(q->x, 2) - 2 * pow(q->y, 2)) * z);
}

t_dot		init_rotate(t_main **ptr, int x, int y, int z)
{
	t_dot	dot;

	x = x + ((*ptr)->map->x_c * -1 / 2);
	y = y + ((*ptr)->map->y_c * -1 / 2);
	dot.x = get_x((*ptr)->q, x, y, z);
	dot.y = get_y((*ptr)->q, x, y, z);
	dot.z = get_z((*ptr)->q, x, y, z);
	return (dot);
}
