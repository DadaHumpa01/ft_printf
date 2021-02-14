/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:00:53 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/14 16:12:31 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test(char *str, t_mastronzo *dado, size_t i)
{
	if (dado->meno == 1)
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
				while (dado->precisione != 0)
				{
					dado->ritorno += 1;
					dado->precisione -= 1;
					write(1, &str[i++], 1);
				}
			}
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
		if (dado->precisione >= 0 && dado->precisione <= ft_strlen(str))
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
	test(str, dado, 0);
	if (f == 1)
		free(str);
	return (1);
}
