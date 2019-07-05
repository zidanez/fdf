/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:15:07 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 15:30:30 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p_list;

	if (!(p_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		p_list->content = NULL;
		p_list->content_size = 0;
	}
	else
	{
		if (!(p_list->content = malloc(content_size)))
		{
			free(p_list);
			return (NULL);
		}
		ft_memcpy(p_list->content, content, content_size);
		p_list->content_size = content_size;
	}
	p_list->next = NULL;
	return (p_list);
}
