/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:14:19 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/04 23:27:38 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
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
	while (haystack[i1] && i1 <= n)
	{
		if (len + i1 <= n && !ft_memcmp(haystack + i1, needle, len))
		{
			return (p + i1);
		}
		i1++;
	}
	return (NULL);
}
