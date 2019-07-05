/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:41:44 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/10 15:19:05 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *str)
{
	size_t	i;
	size_t	j;
	size_t	iter;
	char	*copy;
	char	tmp;

	i = 0;
	j = ft_strlen(str);
	iter = j / 2;
	copy = ft_strnew(j);
	while (iter-- > 0)
	{
		tmp = str[i];
		copy[i] = str[j - i - 1];
		copy[j - i - 1] = tmp;
		i++;
	}
	copy[j + 1] = '\0';
	return (copy);
}
