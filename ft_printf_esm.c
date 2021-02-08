/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_esm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:18:02 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/02 11:50:53 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	esa_min(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		i;

	i = va_arg(lista, int);
	str_num = ft_itoa_esa(i);
	ft_stampo_stringhe(str_num, dado);
	free(str_num);
	return (1);
}
