/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:50:08 by dbrignon          #+#    #+#             */
/*   Updated: 2021/01/29 09:39:55 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lennum(int num)
{
	int count;

	count = 0;
	if (num == 0)
		count += 1;
	if (num <= -1)
		count = count + 1;
	while (num != 0)
	{
		num = num / 10;
		count += 1;
	}
	return (count);
}

char	*ft_write(int lenim, int neg, unsigned int num, char *str)
{
	char	res;

	str[lenim] = '\0';
	while (lenim >= (0 + neg))
	{
		res = num % 10 + '0';
		num = num / 10;
		str[lenim - 1] = res;
		lenim--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int num)
{
	char			*str;
	int				lenim;
	int				neg;
	unsigned int	n;

	neg = 0;
	lenim = lennum(num);
	n = num;
	if (num < 0)
	{
		neg += 1;
		n = num * (-1);
	}
	if (!(str = malloc(sizeof(char) * (lenim + 1))))
		return (NULL);
	ft_write(lenim, neg, n, str);
	return (str);
}