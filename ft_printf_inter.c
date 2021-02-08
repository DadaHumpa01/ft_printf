/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_inter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:58:09 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/02 11:50:57 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	interi(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		i;

	i = va_arg(lista, int);
	str_num = ft_itoa(i);
	ft_stampo_stringhe(str_num, dado);
	free(str_num);
	return (1);
}
