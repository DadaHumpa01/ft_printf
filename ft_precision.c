/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:09:09 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/04 12:28:38 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mod_atoi(const char *str, t_mastronzo *dado, size_t i, int type)
{
	int stop;
	int res;

	stop = 0;
	res = 0;
	while (str[i] != '\0' && stop != 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i++] - '0';
		else
			stop += 1;
	}
	if (type == 1)
		dado->precisione += res;
	else if (type == 2)
		dado->width += res;
	return (i);
}

int		precision(const char *str, t_mastronzo *dado, size_t i, va_list lista)
{
	int val;
	int stop;

	stop = 0;
	val = 0;
	while (str[i] != 0 && stop != 1)
	{
		if (str[i] == '*')
		{
			val = va_arg(lista, int);
			dado->precisione += val;
			return (i + 1);
		}
		else
		{
			i = mod_atoi(str, dado, i, 1);
			stop += 1;
		}
	}
	return (i);
}
