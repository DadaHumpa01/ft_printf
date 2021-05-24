/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_esa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:16:26 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/24 10:47:58 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	linnum(unsigned int num)
{
	int	count;

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

char	*ft_write_itoa(int lenim, unsigned int num, char *str)
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

char	*ft_itoa_esa(unsigned int num)
{
	char			*str;
	int				lenim;
	unsigned int	n;

	lenim = linnum(num);
	n = num;
	str = malloc(sizeof(char) * (lenim + 1));
	if (!str)
		return (NULL);
	ft_write_itoa(lenim, n, str);
	return (str);
}
