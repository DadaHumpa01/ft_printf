/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:45:32 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/12 18:13:19 by dbrignon         ###   ########.fr       */
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
			dado->ritorno += 1;
		}
		write(1, "0x", 2);
		dado->ritorno += 2;
		while (str[i] != 0)
		{
			write(1, &str[i++], 1);
		}
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
	size_t i;

	i = 0;
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