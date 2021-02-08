/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:50:18 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/01 16:51:08 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sentenza(unsigned int num)
{
	size_t count;

	count = 0;
	if (num == 0)
		count += 1;
	while (num != 0)
	{
		num = num / 10;
		count = count + 1;
	}
	return (count);
}

char	*farcitura(int verdetto, char *str, unsigned int num)
{
	char res;

	str[verdetto] = '\0';
	while (verdetto >= 0)
	{
		res = num % 10 + '0';
		num = num / 10;
		str[verdetto - 1] = res;
		verdetto--;
	}
	return (str);
}

char	*itoa_unsigned(unsigned int num)
{
	int		verdetto;
	char	*str;

	verdetto = sentenza(num);
	if (!(str = malloc(sizeof(char) * (verdetto + 1))))
		return (NULL);
	farcitura(verdetto, str, num);
	return (str);
}
