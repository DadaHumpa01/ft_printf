/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:45:32 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/02 11:51:00 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer(va_list lista, t_mastronzo *dado)
{
	unsigned long	car;
	char			*str;

	car = va_arg(lista, unsigned long);
	str = ft_itoa_point(car);
	write(1, "0x", 2);
	ft_stampo_stringhe(str, dado);
	free(str);
	return (1);
}