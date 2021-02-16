/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unisgnedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:49:17 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/16 11:39:17 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int(va_list lista, t_mastronzo *dado)
{
	char			*str;
	unsigned int	num;
	int				a;

	a = 0;
	num = va_arg(lista, unsigned int);
	str = itoa_unsigned(num);
	if (num == 0)
		a = zero_num(dado);
	else
		prima_fase_stampa(str, dado);
	if (a == 1)
		prima_fase_stampa(str, dado);
	free(str);
	return (1);
}
