/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:07:46 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/12 18:13:40 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_ricerca(const char *str, size_t i, t_mastronzo *dado,
			va_list lista)
{
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			dado->meno = 1;
		else if (str[i] == '0')
			dado->zero = 1;
		i++;
	}
	if (str[i] == '*' || (str[i] >= '1' && str[i] <= '9'))
		i = width(str, i, dado, lista);
	if (str[i] == '.')
		i = precision(str, dado, i + 1, lista);
	return (i);
}

int		ricercatore(const char *str, size_t i, va_list lista, t_mastronzo *dado)
{
	if (str[i] == 'c')
		carattere(lista, dado);
	else if (str[i] == 'd' || str[i] == 'i')
		interi(lista, dado);
	else if (str[i] == 'x')
		esa_min(lista, dado);
	else if (str[i] == 'X')
		esa_man(lista, dado);
	else if (str[i] == 'u')
		unsigned_int(lista, dado);
	else if (str[i] == 's')
		putstr(lista, dado);
	else if (str[i] == '%')
		perct(dado);
	else if (str[i] == 'p')
		pointer(lista, dado);
	return (i);
}

void	iter(const char *str, va_list lista, t_mastronzo *dado)
{
	size_t i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			reset(dado);
			i = flag_ricerca(str, i + 1, dado, lista);
			i = ricercatore(str, i, lista, dado);
		}
		else
		{
			write(1, &str[i], 1);
			dado->ritorno += 1;
		}
		i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		lista;
	t_mastronzo dado;

	va_start(lista, str);
	dado.ritorno = 0;
	iter(str, lista, &dado);
	va_end(lista);
	return (dado.ritorno);
}
