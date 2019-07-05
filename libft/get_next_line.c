/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:55 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/06/18 13:48:57 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*rewrite(char **dest, int fd, char *src)
{
	char	*new;

	if (!src)
		return (dest[fd]);
	new = ft_strjoin(dest[fd], src);
	free(dest[fd]);
	return (new);
}

int			write_line(char **buff_fd, int fd, char **line, int fl)
{
	char	*tmp;

	if (fl == -1)
		fl = ft_strchri(buff_fd[fd], '\n');
	if (fl == -1)
	{
		*line = ft_strdup(buff_fd[fd]);
		ft_strdel(&buff_fd[fd]);
	}
	else
	{
		*line = ft_strsub(buff_fd[fd], 0, fl);
		tmp = ft_strdup(&buff_fd[fd][fl + 1]);
		free(buff_fd[fd]);
		buff_fd[fd] = tmp;
	}
	if (!*line)
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff_fd[MAX_FD];
	char		rd_buff[BUFF_SIZE + 1];
	int			rd;
	int			fl;

	if (fd < 0 || !line || read(fd, rd_buff, 0) < 0)
		return (-1);
	if (!buff_fd[fd])
		buff_fd[fd] = ft_strnew(1);
	if ((fl = ft_strchri(buff_fd[fd], '\n')) == -1)
	{
		while ((rd = read(fd, rd_buff, BUFF_SIZE)) > 0)
		{
			rd_buff[rd] = '\0';
			buff_fd[fd] = rewrite(buff_fd, fd, rd_buff);
			if (ft_strchr(rd_buff, '\n'))
				break ;
		}
	}
	if (buff_fd[fd][0] == '\0' && rd_buff[0] != '\n')
		return (0);
	return (write_line(buff_fd, fd, line, fl));
}
