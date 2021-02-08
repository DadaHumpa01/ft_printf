/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_esaman.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:17:56 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/02 11:50:55 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		esa_man(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		c;
	int		i;

	c = 0;
	i = va_arg(lista, int);
	str_num = ft_itoa_esa(i);
	while (str_num[c] != 0)
	{
		if (str_num[c] >= 'a' && str_num[c] <= 'z')
			str_num[c] = str_num[c] - 32;
		c++;
	}
	ft_stampo_stringhe(str_num, dado);
	free(str_num);
	return (1);
}