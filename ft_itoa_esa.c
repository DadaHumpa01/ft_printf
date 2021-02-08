/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_esa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:16:26 by dbrignon          #+#    #+#             */
/*   Updated: 2021/01/29 16:38:28 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		linnum(int num)
{
	int count;

	count = 0;
	if (num == 0)
		count += 1;
	if (num <= -1)
		count = count + 1;
	while (num != 0)
	{
		num = num / 16;
		count += 1;
	}
	return (count);
}

char	*ft_write_itoa(int lenim, int neg, unsigned int num, char *str)
{
	int	patty;

	str[lenim] = '\0';
	while (lenim >= (0 + neg))
	{
		patty = num % 16;
		num = num / 16;
		if (patty >= 10)
		{
			str[lenim - 1] = patty % 10 + 'a';
		}
		if (patty <= 9)
			str[lenim - 1] = patty + '0';
		lenim--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_esa(int num)
{
	char			*str;
	int				lenim;
	int				neg;
	unsigned int	n;

	neg = 0;
	lenim = linnum(num);
	n = num;
	if (num < 0)
	{
		neg += 1;
		n = num * (-1);
	}
	if (!(str = malloc(sizeof(char) * (lenim + 1))))
		return (NULL);
	ft_write_itoa(lenim, neg, n, str);
	return (str);
}
