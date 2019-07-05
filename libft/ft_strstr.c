/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:51:39 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/04 23:28:04 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i1;
	size_t		len;
	char		*p;

	i1 = 0;
	len = ft_strlen(needle);
	p = (char*)haystack;
	if (!len)
	{
		return (p);
	}
	while (haystack[i1])
	{
		if (!ft_memcmp(haystack + i1, needle, len))
		{
			return (p + i1);
		}
		i1++;
	}
	return (NULL);
}
