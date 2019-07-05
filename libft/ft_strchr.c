/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:23:17 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/04 22:38:17 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)s;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (p + i);
		}
		i++;
	}
	if (s[i] == c)
	{
		return (p + i);
	}
	return (NULL);
}
