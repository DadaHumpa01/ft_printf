/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:00:53 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/16 12:20:04 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_split2(char *str, t_mastronzo *dado, size_t i)
{
	if (dado->width > dado->precisione)
	{
		dado->width = (dado->width - dado->precisione);
		while (dado->width != 0)
		{
			dado->ritorno += 1;
			write(1, " ", 1);
			dado->width -= 1;
		}
		while (dado->precisione != 0)
		{
			dado->ritorno += 1;
			dado->precisione -= 1;
			write(1, &str[i++], 1);
		}
	}
	else
	{
		while (dado->precisione != 0)
		{
			dado->ritorno += 1;
			dado->precisione -= 1;
			write(1, &str[i++], 1);
		}
	}
}

void	test_split3(char *str, t_mastronzo *dado)
{
	if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
	{
		test_split2(str, dado, 0);
	}
	else
	{
		if (dado->width > ft_strlen(str))
		{
			while (dado->width > ft_strlen(str))
			{
				dado->ritorno += 1;
				dado->width -= 1;
				write(1, " ", 1);
			}
		}
		ft_stampo_stringhe(str, dado);
	}
}

void	test_split1(char *str, t_mastronzo *dado, size_t i)
{
	if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
	{
		if (dado->width > dado->precisione)
		{
			dado->width = (dado->width - dado->precisione);
			while (dado->precisione != 0)
			{
				dado->precisione -= 1;
				dado->ritorno += 1;
				write(1, &str[i++], 1);
			}
			while (dado->width != 0)
			{
				write(1, " ", 1);
				dado->width -= 1;
				dado->ritorno += 1;
			}
		}
		else
		{
			stampa_fino_a_prec(str, dado, 0);
		}
	}
}

void	test(char *str, t_mastronzo *dado)
{
	if (dado->meno == 1)
	{
		if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
		{
			test_split1(str, dado, 0);
		}
		else
		{
			ft_stampo_stringhe(str, dado);
			if (dado->width > ft_strlen(str))
			{
				while (dado->width != ft_strlen(str))
				{
					dado->ritorno += 1;
					dado->width -= 1;
					write(1, " ", 1);
				}
			}
		}
	}
	else if (dado->meno == 0)
	{
		test_split3(str, dado);
	}
}

int		putstr(va_list lista, t_mastronzo *dado)
{
	char	*str;
	int		f;

	f = 0;
	str = va_arg(lista, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		f = 1;
	}
	if (dado->width < 0)
		dado->meno = 1;
	test(str, dado);
	if (f == 1)
		free(str);
	return (1);
}
