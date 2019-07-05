/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:32:24 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 21:05:38 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_hed.h"

void		free_tarray(char ***array)
{
	int		i;

	i = -1;
	while ((*array)[++i])
		free((*array)[i]);
	free((*array));
}

t_mas		*mas_init(int fd)
{
	t_mas	*res;
	char	*str;
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(res = (t_mas*)malloc(sizeof(t_mas))))
		exit(0);
	if (get_next_line(fd, &str) == 0)
		exit(0);
	split = ft_strsplit(str, ' ');
	free(str);
	while (split[i])
		i++;
	free_tarray(&split);
	while (get_next_line(fd, &str) && j++)
		free(str);
	if (!(res->map = (int**)malloc(sizeof(int*) * j)))
		exit(0);
	res->y_c = j;
	res->x_c = i;
	init_columns_mas(&res);
	return (res);
}

int			**fill_mas(int fd, t_mas *mass)
{
	char	*str;
	char	**split;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(fd, &str))
	{
		i = -1;
		split = ft_strsplit(str, ' ');
		while (split[++i])
		{
			mass->map[j][i] = ft_atoi(split[i]);
			free(split[i]);
		}
		free(str);
		free(split);
		j++;
	}
	close(fd);
	return (mass->map);
}

t_mas		*read_f(char *file)
{
	int		fd;
	t_mas	*res;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr(" No file\n");
		exit(0);
	}
	res = mas_init(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (validate_map(&res, fd) == 0)
	{
		ft_putstr(" file validation error\n");
		close(fd);
		exit(0);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	res->map = fill_mas(fd, res);
	return (res);
}
