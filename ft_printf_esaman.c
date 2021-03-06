/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_esaman.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:17:56 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/24 10:55:15 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zeroo(char *str, t_mastronzo *dado)
{
	while (dado->width != ft_strlen(str))
	{
		dado->ritorno += 1;
		dado->width -= 1;
		write(1, "0", 1);
	}
	ft_stampo_stringhe(str, dado);
}

void	prec_with(t_mastronzo *dado)
{
	if (dado->width >= 0)
	{
		if (dado->meno == 0 && dado->zero == 1)
		{
			while (dado->width != 0)
			{
				write(1, "0", 1);
				dado->width -= 1;
				dado->ritorno += 1;
			}
		}
		else
		{
			while (dado->width != 0)
			{
				write(1, " ", 1);
				dado->width -= 1;
				dado->ritorno += 1;
			}
		}
	}
	return ;
}

int	esa_man(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		c;
	int		i;
	int		a;

	a = 0;
	c = 0;
	i = va_arg(lista, int);
	str_num = ft_itoa_esa(i);
	while (str_num[c] != 0)
	{
		if (str_num[c] >= 'a' && str_num[c] <= 'z')
			str_num[c] = str_num[c] - 32;
		c++;
	}
	if (i == 0)
		a = zero_num(dado);
	else
		prima_fase_stampa(str_num, dado);
	if (a == 1)
		prima_fase_stampa(str_num, dado);
	free(str_num);
	return (1);
}
