/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:36:23 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/14 14:44:11 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*newptr;

	if (ptr == NULL)
		return (malloc(size));
	else if (ptr != NULL && size == 0)
	{
		ft_memdel(ptr);
		return (malloc(1));
	}
	newptr = malloc(size);
	if (newptr != NULL)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(ptr);
	}
	return (newptr);
}
