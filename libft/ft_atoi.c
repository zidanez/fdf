/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:53:08 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 19:38:39 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspase_skip(char *c)
{
	int i;

	i = 0;
	while (c[i] == ' '
	|| c[i] == '\n'
	|| c[i] == '\t'
	|| c[i] == '\f'
	|| c[i] == '\r'
	|| c[i] == '\v')
	{
		i++;
	}
	return (i);
}

static int	chek_long(int sign, unsigned long rez, char c)
{
	unsigned long	max_l;

	max_l = 9223372036854775807;
	if (sign > 0 && (rez > max_l / 10 ||
	(rez == max_l / 10 && (unsigned long)(c - '0') > max_l % 10)))
		return (-1);
	else if (sign < 0 && (rez > max_l / 10 ||
	(rez == max_l / 10 && (unsigned long)(c - '0') > (max_l % 10 + 1))))
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	unsigned long	rez;
	int				sign;
	int				i;

	rez = 0;
	sign = 1;
	i = (ft_isspase_skip((char*)str));
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (chek_long(sign, rez, str[i]) == -1)
			return (-1);
		else if (chek_long(sign, rez, str[i]) == 0)
			return (0);
		if (str[i] < '0' || str[i] > '9')
			break ;
		rez = rez * 10 + (str[i++] - '0');
	}
	return (rez * sign);
}
