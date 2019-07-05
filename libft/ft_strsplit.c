/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:18:36 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 20:22:21 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	ft_count_word(const char *s, char c)
{
	int		i;
	int		fl;
	int		count;

	i = 0;
	fl = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && fl)
		{
			count++;
			fl = 0;
		}
		else if (s[i] == c && !fl)
		{
			fl = 1;
		}
		i++;
	}
	return (count);
}

static int	ft_len_world(const char *s, int i, char c)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static char	*ft_write_word(const char *s, int i, char c, char **strsplit)
{
	char	*word;
	int		j;

	j = 0;
	word = (char*)malloc(sizeof(char) * ft_len_world(s, i, c) + 1);
	if (!word)
	{
		ft_free(strsplit);
		return (NULL);
	}
	while (s[i] && s[i] != c)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	nw;
	size_t	i;
	size_t	i2;

	if (!s)
		return (NULL);
	nw = ft_count_word(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * nw + 1)))
		return (NULL);
	i = 0;
	i2 = 0;
	while (i < nw && split)
	{
		while (s[i2] == c)
			i2++;
		split[i] = ft_write_word(s, i2, c, split);
		if (!split)
			return (NULL);
		i++;
		while (s[i2] != c && s[i2] != '\0')
			i2++;
	}
	split[i] = NULL;
	return (split);
}
