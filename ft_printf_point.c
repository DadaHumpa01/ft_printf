/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:45:32 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/16 11:39:01 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	point_flag3(t_mastronzo *dado)
{
	if (dado->width > 2)
	{
		while (dado->width != 2)
		{
			write(1, " ", 1);
			dado->width -= 1;
			dado->ritorno += 1;
		}
		write(1, "0x", 2);
		dado->ritorno += 2;
	}
	else
	{
		write(1, "0x", 2);
		dado->ritorno += 2;
	}
}

void	point_flag2(char *str, t_mastronzo *dado)
{
	if (dado->width > ft_strlen(str) + 2)
	{
		while (dado->width != ft_strlen(str) + 2)
		{
			dado->width -= 1;
			write(1, " ", 1);
			dado->ritorno += 1;
		}
		write(1, "0x", 2);
		dado->ritorno += 2;
		ft_stampo_stringhe(str, dado);
	}
	else
	{
		dado->ritorno += 2;
		write(1, "0x", 2);
		ft_stampo_stringhe(str, dado);
	}
}

void	point_flag(char *str, t_mastronzo *dado)
{
	if (dado->meno == 1)
	{
		write(1, "0x", 2);
		dado->ritorno += 2;
		ft_stampo_stringhe(str, dado);
		if (dado->width > ft_strlen(str) + 2)
		{
			while (dado->width != ft_strlen(str) + 2)
			{
				dado->width -= 1;
				write(1, " ", 1);
				dado->ritorno += 1;
			}
		}
	}
	else if (dado->meno == 0 && dado->precisione != 0)
		point_flag2(str, dado);
	else
		point_flag3(dado);
}

int		pointer(va_list lista, t_mastronzo *dado)
{
	unsigned long	car;
	char			*str;

	car = va_arg(lista, unsigned long);
	str = ft_itoa_point(car);
	point_flag(str, dado);
	free(str);
	return (1);
}
