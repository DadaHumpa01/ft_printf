/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:38:47 by dbrignon          #+#    #+#             */
/*   Updated: 2021/01/29 18:18:52 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_it(long num)
{
	int count;

	count = 0;
	if (num == 0)
		count += 1;
	while (num != 0)
	{
		num = num / 16;
		count += 1;
	}
	return (count);
}

char	*ft_write_me(int lenim, unsigned long num, char *str)
{
	int	patty;

	str[lenim] = '\0';
	while (lenim >= 0)
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
	return (str);
}

char	*ft_itoa_point(unsigned long num)
{
	char			*str;
	long			lenim;
	unsigned long	n;

	lenim = num_it(num);
	n = num;
	if (!(str = malloc(sizeof(char) * (lenim + 1))))
		return (NULL);
	ft_write_me(lenim, n, str);
	return (str);
}
