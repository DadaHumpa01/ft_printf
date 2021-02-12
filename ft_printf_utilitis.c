/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilitis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:53:17 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/12 15:09:12 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stampo_stringhe(const char *str, t_mastronzo *dado)
{
	size_t c;

	c = 0;
	while (str[c] != 0)
	{
		write(1, &str[c++], 1);
		dado->ritorno += 1;
	}
	return (1);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		reset(t_mastronzo *dado)
{
	dado->width = 0;
	dado->precisione = -1;
	dado->meno = 0;
	dado->zero = 0;
}