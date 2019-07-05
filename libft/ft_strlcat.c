/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:28:37 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 19:30:54 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t is;
	size_t id;

	id = ft_strlen(dst);
	is = 0;
	if (id >= size)
		return (size + ft_strlen(src));
	size = size - id - 1;
	while (src[is] && is < size)
	{
		dst[id + is] = src[is];
		is++;
	}
	dst[id + is] = '\0';
	return (id + ft_strlen(src));
}
