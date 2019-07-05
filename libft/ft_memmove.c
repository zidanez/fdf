/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:50:14 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/04 15:09:17 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char*)dst;
	s = (char*)src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len--)
		{
			*d-- = *s--;
		}
	}
	return (dst);
}
