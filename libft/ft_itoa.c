/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:47:43 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/04/09 16:24:35 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int		rez;

	rez = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		rez++;
	}
	return (rez);
}

static char	*get_mem(int n)
{
	char	*rez;
	int		digit;

	if (n <= 0)
	{
		n = -n;
		digit = ft_digit(n) + 1;
		rez = (char*)malloc(sizeof(char) * ++digit);
	}
	else
	{
		digit = ft_digit(n);
		rez = (char*)malloc(sizeof(char) * digit);
	}
	return (rez);
}

char		*ft_itoa(int n)
{
	int		i;
	int		digits;
	int		sign;
	char	*rez;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(rez = get_mem(n)))
		return (NULL);
	digits = (n <= 0) ? (ft_digit(n) + 1) : ft_digit(n);
	if ((sign = n) < 0)
		n = -n;
	(n == 0) ? rez[0] = '0' : rez[0];
	rez[digits--] = '\0';
	while (n > 0)
	{
		rez[digits--] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		rez[digits] = '-';
	return (rez);
}
