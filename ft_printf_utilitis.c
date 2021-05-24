/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilitis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:53:17 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/24 11:01:37 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_stampo_stringhe(const char *str, t_mastronzo *dado)
{
	size_t	c;

	c = 0;
	while (str[c] != 0)
	{
		write(1, &str[c++], 1);
		dado->ritorno += 1;
	}
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	reset(t_mastronzo *dado)
{
	dado->width = 0;
	dado->precisione = -1;
	dado->meno = 0;
	dado->zero = 0;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*memd;
	unsigned const char	*mems;
	size_t				i;

	memd = dst;
	mems = src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		memd[i] = mems[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy((void *)dst, (const void *)s1, len);
	dst[len] = '\0';
	return (dst);
}
