/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:01:49 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/06 16:19:44 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fs;
	size_t	i1;

	if (!s1 || !s2)
		return (NULL);
	fs = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i1 = 0;
	if (!fs)
		return (NULL);
	while (*s1)
	{
		fs[i1] = *s1++;
		i1++;
	}
	while (*s2)
	{
		fs[i1] = *s2++;
		i1++;
	}
	fs[i1] = '\0';
	return (fs);
}
