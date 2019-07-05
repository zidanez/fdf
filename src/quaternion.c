/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:13:49 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 20:38:29 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/quaternion.h"

t_quatr		*new_quatr(float w, float x, float y, float z)
{
	t_quatr *res;

	if (!(res = (t_quatr*)malloc(sizeof(t_quatr))))
	{
		ft_putstr("Can't malloc new_quatr\n");
		exit(0);
	}
	res->w = w;
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

t_quatr		*multiply(t_quatr **q1, t_quatr **q2)
{
	float w;
	float x;
	float y;
	float z;

	w = (*q1)->w * (*q2)->w - (*q1)->x * (*q2)->x - (*q1)->y * (*q2)->y -
			(*q1)->z * (*q2)->z;
	x = (*q1)->w * (*q2)->x + (*q1)->x * (*q2)->w + (*q1)->y * (*q2)->z -
			(*q1)->z * (*q2)->y;
	y = (*q1)->w * (*q2)->y - (*q1)->x * (*q2)->z + (*q1)->y * (*q2)->w +
			(*q1)->z * (*q2)->x;
	z = (*q1)->w * (*q2)->z + (*q1)->x * (*q2)->y - (*q1)->y * (*q2)->x +
			(*q1)->z * (*q2)->w;
	free((*q1));
	if (!(*q2))
		free((*q2));
	free((*q2));
	(*q2) = NULL;
	return (new_quatr(w, x, y, z));
}

void		quatr_normalize(t_quatr **q1)
{
	float magnitude;

	magnitude = sqrt((*q1)->w * (*q1)->w + (*q1)->x * (*q1)->x +
			(*q1)->y * (*q1)->y + (*q1)->z * (*q1)->z);
	(*q1)->w /= magnitude;
	(*q1)->x /= magnitude;
	(*q1)->y /= magnitude;
	(*q1)->z /= magnitude;
}

t_quatr		*rotate(t_quatr **q1, double angle)
{
	float w;
	float x;
	float y;
	float z;

	angle = M_PI / 180 * angle;
	w = cos(angle / 2);
	x = (*q1)->x * sin(angle / 2);
	y = (*q1)->y * sin(angle / 2);
	z = (*q1)->z * sin(angle / 2);
	free((*q1));
	return (new_quatr(w, x, y, z));
}
