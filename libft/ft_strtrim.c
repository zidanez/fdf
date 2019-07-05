/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:22:21 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 19:30:54 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspase(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	fi;
	char	*fs;
	size_t	len;

	i = 0;
	fi = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isspase(s[i]))
		i++;
	if (i == len)
		return (ft_memalloc(1));
	while (ft_isspase(s[len - 1]))
		len--;
	fs = (char*)malloc(sizeof(char) * (len - i) + 1);
	if (!fs)
		return (NULL);
	while (i < len)
	{
		fs[fi++] = s[i++];
	}
	fs[fi] = '\0';
	return (fs);
}
