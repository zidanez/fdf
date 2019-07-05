/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:15:25 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/06 22:15:29 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_QUATERNION_H
# define FDF_QUATERNION_H

# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_quatr
{
	float		w;
	float		x;
	float		y;
	float		z;
}				t_quatr;

t_quatr			*new_quatr(float w, float x, float y, float z);
t_quatr			*rotate(t_quatr **q1, double angle);
t_quatr			*multiply(t_quatr **q1, t_quatr **q2);
void			quatr_normalize(t_quatr **q1);

#endif
