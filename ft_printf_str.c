/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:00:53 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/08 15:03:30 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(va_list lista, t_mastronzo *dado)
{
	char	*str;

	str = va_arg(lista, char *);
	if (str == NULL)
		write(1, "succhia", 7);
	else
		ft_stampo_stringhe(str, dado);
	return (1);
}
