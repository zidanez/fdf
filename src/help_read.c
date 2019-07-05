/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:26:23 by fnancy            #+#    #+#             */
/*   Updated: 2019/06/19 00:26:23 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_hed.h"

void		init_columns_mas(t_mas **res)
{
	int		j;

	j = -1;
	while (++j < (*res)->y_c)
		if (!((*res)->map[j] = (int *)malloc(sizeof(int) * (*res)->x_c)))
			exit(0);
}

int			validate_map(t_mas **res, int fd)
{
	int		j;
	int		i;
	char	*str;
	char	**split;

	j = -1;
	while (++j < (*res)->y_c)
	{
		get_next_line(fd, &str);
		split = ft_strsplit(str, ' ');
		i = -1;
		while (split[++i])
			free(split[i]);
		if (i != (*res)->x_c)
		{
			free(str);
			free(split);
			return (0);
		}
		free(split);
		free(str);
	}
	return (1);
}
