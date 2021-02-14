/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilites2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:44:35 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/14 16:32:03 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stampo_stringhe_neg(char *str, t_mastronzo *dado)
{
	size_t i;

	i = 1;
	while (str[i] != '\0')
	{
		dado->ritorno += 1;
		write(1, &str[i++], 1);
	}
	return (1);
}

void	zeroo_neg(char *str, t_mastronzo *dado)
{
	dado->ritorno += 1;
	write(1, "-", 1);
	while (dado->width != ft_strlen(str))
	{
		dado->ritorno += 1;
		dado->width -= 1;
		write(1, "0", 1);
	}
	ft_stampo_stringhe_neg(str, dado);
}