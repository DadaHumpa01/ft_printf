/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:36:49 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/16 11:42:02 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width(const char *str, size_t i, t_mastronzo *dado, va_list lista)
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
			if (val < 0)
			{
				dado->meno = 1;
				val = -val;
			}
			dado->width = val;
			return (i + 1);
		}
		else
		{
			i = mod_atoi(str, dado, i, 2);
			stop += 1;
		}
	}
	return (i);
}
