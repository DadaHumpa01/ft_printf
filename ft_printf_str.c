/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:00:53 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/11 15:31:58 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test(char *str, t_mastronzo *dado, size_t i)
{
	if (dado->meno == 1)
	{
		if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
		{
			if (dado->width > ft_strlen(str) - dado->precisione || dado->width > dado->precisione)
			{
				dado->width = (dado->width - dado->precisione);
				while (dado->precisione != 0)
				{
					dado->precisione -= 1;
					write(1, &str[i++], 1);
				}
				while (dado->width != 0)
				{
					write(1, " ", 1);
					dado->width -= 1;
				}
			}
			else
			{
				while (dado->precisione != 0)
				{
					dado->precisione -= 1;
					write(1, &str[i++], 1);
				}
			}
		}
		else
		{
			while (str[i] != 0)
			{
				write(1, &str[i++], 1);
			}
			if (dado->width > ft_strlen(str))
			{
				while (dado->width != ft_strlen(str))
				{
					dado->width -= 1;
					write(1, " ", 1);
				}
			}
		}
	}
	else if (dado->meno == 0)
	{
		if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
		{
			if (dado->width > ft_strlen(str) - dado->precisione || dado->width > dado->precisione)
			{
				dado->width = (dado->width - dado->precisione);
				while (dado->width != 0)
				{
					write(1, " ", 1);
					dado->width -= 1;
				}
				while (dado->precisione != 0)
				{
					dado->precisione -= 1;
					write(1, &str[i++], 1);
				}
			}
			else
			{
				while (dado->precisione != 0)
				{
					dado->precisione -= 1;
					write(1, &str[i++], 1);
				}
			}
		}
		else
		{
			if (dado->width > ft_strlen(str))
			{
				while (dado->width != ft_strlen(str))
				{
					dado->width -= 1;
					write(1, " ", 1);
				}
			}
			while (str[i] != 0)
			{
				write(1, &str[i++], 1);
			}
		}
	}
}

int		putstr(va_list lista, t_mastronzo *dado)
{
	char	*str;

	str = va_arg(lista, char *);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * (6 + 1));
		str = "(null)";
	}
	if (dado->width < 0)
		dado->meno = 1;
	test(str, dado, 0);
	return (1);
}
