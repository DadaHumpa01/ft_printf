/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_esm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:18:02 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/16 11:02:55 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaziatura4(char *str, t_mastronzo *dado)
{
	if (dado->width >= dado->precisione)
	{
		while (dado->width-- != dado->precisione)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
		}
	}
	while (dado->precisione-- != ft_strlen(str))
	{
		write(1, "0", 1);
		dado->ritorno += 1;
	}
	ft_stampo_stringhe(str, dado);
}

void	spaziatura2(char *str, t_mastronzo *dado)
{
	if (dado->zero == 1 && dado->precisione <= -1 &&
		dado->width > ft_strlen(str))
		zeroo(str, dado);
	else if (dado->precisione <= ft_strlen(str))
	{
		if (dado->width >= ft_strlen(str))
		{
			while (dado->width-- != ft_strlen(str))
			{
				write(1, " ", 1);
				dado->ritorno += 1;
			}
		}
		ft_stampo_stringhe(str, dado);
	}
	else
		spaziatura4(str, dado);
}

void	spaziatura1(char *str, t_mastronzo *dado)
{
	int backup;

	backup = dado->precisione;
	while (dado->precisione-- != ft_strlen(str))
	{
		write(1, "0", 1);
		dado->ritorno += 1;
	}
	ft_stampo_stringhe(str, dado);
	if (dado->width >= backup)
	{
		while (dado->width-- != backup)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
		}
	}
}

void	prima_fase_stampa(char *str, t_mastronzo *dado)
{
	if (dado->meno == 1)
	{
		if (dado->precisione <= ft_strlen(str))
		{
			ft_stampo_stringhe(str, dado);
			if (dado->width >= ft_strlen(str))
			{
				while (dado->width-- != ft_strlen(str))
				{
					write(1, " ", 1);
					dado->ritorno += 1;
				}
			}
		}
		else
			spaziatura1(str, dado);
	}
	else
		spaziatura2(str, dado);
}

int		esa_min(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		i;
	int		a;

	a = 0;
	i = va_arg(lista, unsigned int);
	str_num = ft_itoa_esa(i);
	if (i == 0)
		a = zero_num(dado);
	else
		prima_fase_stampa(str_num, dado);
	if (a == 1)
		prima_fase_stampa(str_num, dado);
	free(str_num);
	return (1);
}
