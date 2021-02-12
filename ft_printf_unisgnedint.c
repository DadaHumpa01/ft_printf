/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unisgnedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:49:17 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/12 11:27:30 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int(va_list lista, t_mastronzo *dado)
{
	char			*str;
	unsigned int	num;

	num = va_arg(lista, unsigned int);
	str = itoa_unsigned(num);
	prima_fase_stampa(str, dado);
	free(str);
	return (1);
}
