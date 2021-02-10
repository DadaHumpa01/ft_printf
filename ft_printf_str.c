/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:00:53 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/10 12:37:04 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cond3(char *str, t_mastronzo *dado)
{
	size_t i;

	i = 0;
	if (dado->precisione < 0)
		while (str[i] != '\0')
		{
			write(1, &str[i++], 1);
			dado->ritorno += 1;
		}
	else
		while (str[i] != '\0' && dado->precisione != -1)
		{
			write(1, &str[i++], 1);
			dado->ritorno += 1;
			dado->precisione -= 1;
		}
}

void	cond2(char *str, t_mastronzo *dado)
{
	size_t i;
	int x;

	x = 1;
	i = 0;
	if (dado->width > 0 && ft_strlen(str) < dado->width && x == 1)
	{
		while (dado->width != ft_strlen(str))
		{
			write(1, " ", 1);
			dado->ritorno += 1;
			dado->width -= 1;
		}
		while (str[i] != '\0' && dado->precisione != 0)
		{
			write(1, &str[i++], 1);
			dado->ritorno += 1;
			dado->precisione -= 1;
			x = 0;
		}
	}
	else
		cond3(str, dado);
}

void	test(char *str, t_mastronzo *dado)
{
	size_t i;

	i = 0;
	if (dado->meno == 1)
	{
		if (dado->width == 0)
		{
			if (dado->precisione < -1)
			{
				while (str[i] != '\0')
				{
					write(1, &str[i++], 1);
					dado->ritorno += 1;
				}
			}
			else
			{
				while (str[i] != '\0' && dado->precisione != -1)
				{
					write(1, &str[i++], 1);
					dado->ritorno += 1;
					dado->precisione -= 1;
				}
			}
		}
	}
	else
		cond2(str, dado);
}

int	putstr(va_list lista, t_mastronzo *dado)
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
	test(str, dado);
	return (1);
}
