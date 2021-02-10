/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:45:32 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/10 16:53:03 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	point_flag2(char *str, t_mastronzo *dado)
{
	size_t i;

	i = 0;
	if (dado->width > ft_strlen(str) + 2)
	{
		while (dado->width != ft_strlen(str) + 2)
		{
			dado->width -= 1;
			write(1, " ", 1);
		}
		write(1, "0x", 2);
		while (str[i] != 0)
		{
			write(1, &str[i++], 1);
		}
	}
	else
	{
		write(1, "0x", 2);
		while (str[i] != 0)
		{
			write(1, &str[i++], 1);
		}
	}
}

void	point_flag(char *str, t_mastronzo *dado)
{
	size_t i;

	i = 0;
	if (dado->meno == 1)
	{
		write(1, "0x", 2);
		while (str[i] != 0)
		{
			write(1, &str[i++], 1);
		}
		if (dado->width > ft_strlen(str) + 2)
		{
			while (dado->width != ft_strlen(str) + 2)
			{
				dado->width -= 1;
				write(1, " ", 1);
			}
		}
	}
	else
	{
		point_flag2(str, dado);
	}
}

int	pointer(va_list lista, t_mastronzo *dado)
{
	unsigned long	car;
	char			*str;

	car = va_arg(lista, unsigned long);
	str = ft_itoa_point(car);
	point_flag(str, dado);
	free(str);
	return (1);
}