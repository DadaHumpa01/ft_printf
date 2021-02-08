/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unisgnedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:49:17 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/02 11:51:05 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int(va_list lista, t_mastronzo *dado)
{
	char			*str;
	unsigned int	num;

	num = va_arg(lista, unsigned int);
	str = itoa_unsigned(num);
	ft_stampo_stringhe(str, dado);
	free(str);
	return (1);
}
