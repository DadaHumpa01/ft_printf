/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_car.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:05:26 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/10 13:18:48 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero(t_mastronzo *dado)
{
	if (dado->zero == 1)
	{
		while (dado->width != 1)
		{
			dado->width -= 1;
			write(1, "0", 1);
		}
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		while (dado->width != 1)
		{
			dado->width -= 1;
			write(1, "0", 1);
		}
	}
}

int		perct(t_mastronzo *dado)
{
	if (dado->width == 0)
		write(1, "%", 1);
	else if (dado->width > 0 && dado->meno == 0 && dado->zero == 0)
	{
		while (dado->width != 1)
		{
			write(1, " ", 1);
			dado->width -= 1;
		}
		write(1, "%", 1);
	}
	else if (dado->meno == 1)
	{
		write(1, "%", 1);
		while (dado->width != 1)
		{
			write(1, " ", 1);
			dado->width -= 1;
		}
	}
	else
		zero(dado);
	return (1);
}

void		volare(int car, int sing, t_mastronzo *dado)
{
	if (sing == 1)
	{
		write(1, &car, 1);
		dado->ritorno += 1;
		while (dado->width != 1)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
			dado->width -= 1;
		}
	}
	else
	{
		while (dado->width != 1)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
			dado->width -= 1;
		}
		write(1, &car, 1);
		dado->ritorno += 1;
	}
}

int		carattere(va_list lista, t_mastronzo *dado)
{
	int car;

	car = va_arg(lista, int);
	if (dado->width != 0)
	{
		if (dado->width < 0)
			dado->width = dado->width * (-1);
		if (dado->meno == 1)
			volare(car, 1, dado);
		if (dado->meno == 0)
			volare(car, 0, dado);
	}
	else
	{
		write(1, &car, 1);
		dado->ritorno += 1;
	}
	return (1);
}
