/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:26:40 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/06 15:58:12 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fs;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	fs = (char*)malloc((sizeof(char) * len + 1));
	if (!fs)
		return (NULL);
	while (len-- && s[start])
	{
		fs[i++] = s[start++];
	}
	fs[i] = '\0';
	return (fs);
}
