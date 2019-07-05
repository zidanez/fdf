/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:39:03 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 19:30:54 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*p;

	i = ft_strlen(s);
	p = (char*)s;
	while (i > 0)
	{
		if (s[i] == c)
		{
			return (p + i);
		}
		i--;
	}
	if (s[i] == c)
	{
		return (p + i);
	}
	return (NULL);
}
