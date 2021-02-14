/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_inter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:58:09 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/14 18:05:52 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaziatura4_neg(char *str, t_mastronzo *dado)
{
	dado->width -= 1;
	if (dado->width >= dado->precisione)
	{
		while (dado->width-- != dado->precisione)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
		}
	}
	dado->ritorno += 1;
	write(1, "-", 1);
	dado->precisione += 1;
	while (dado->precisione-- != ft_strlen(str))
	{
		write(1, "0", 1);
		dado->ritorno += 1;
	}
	ft_stampo_stringhe_neg(str, dado);
}

void	spaziatura2_neg(char *str, t_mastronzo *dado)
{
	if (dado->precisione == 0)
		prec_with(dado);
	else if (dado->zero == 1 && dado->precisione == -1 &&
		dado->width > ft_strlen(str))
		zeroo_neg(str, dado);
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
		spaziatura4_neg(str, dado);
}

void	spaziatura1_neg(char *str, t_mastronzo *dado)
{
	int backup;

	backup = dado->precisione;
	write(1, "-", 1);
	dado->ritorno += 1;
	dado->precisione += 1;
	dado->width -= 1;
	while (dado->precisione-- != ft_strlen(str))
	{
		write(1, "0", 1);
		dado->ritorno += 1;
	}
	ft_stampo_stringhe_neg(str, dado);
	if (dado->width >= backup)
	{
		while (dado->width-- != backup)
		{
			write(1, " ", 1);
			dado->ritorno += 1;
		}
	}
}

void	prima_fase_stampa_neg(char *str, t_mastronzo *dado)
{
	if (dado->meno == 1)
	{
		if (dado->precisione == 0)
			prec_with(dado);
		else if (dado->precisione <= ft_strlen(str))
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
			spaziatura1_neg(str, dado);
	}
	else
		spaziatura2_neg(str, dado);
}

int		interi(va_list lista, t_mastronzo *dado)
{
	char	*str_num;
	int		i;

	i = va_arg(lista, int);
	str_num = ft_itoa(i);
	if (str_num[0] == '-')
		prima_fase_stampa_neg(str_num, dado);
	else
		prima_fase_stampa(str_num, dado);
	free(str_num);
	return (1);
}
