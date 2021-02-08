/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:15:59 by dbrignon          #+#    #+#             */
/*   Updated: 2021/02/08 14:08:41 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_mastronzo
{
	int				width;
	int				precisione;
	int				zero;
	int				meno;
	size_t			ritorno;
}					t_mastronzo;

int					ft_printf(const char *str, ...);
char				*ft_itoa(int num);
int					interi(va_list lista, t_mastronzo *dado);
int					carattere(va_list lista, t_mastronzo *dado);
int					putstr(va_list lista, t_mastronzo *dado);
char				*ft_itoa_esa(int num);
int					esa_min(va_list lista, t_mastronzo *dado);
int					esa_man(va_list lista, t_mastronzo *dado);
int					ft_stampo_stringhe(const char *str, t_mastronzo *dado);
int					pointer(va_list lista, t_mastronzo *dado);
char				*ft_itoa_point(unsigned long num);
char				*itoa_unsigned(unsigned int num);
int					unsigned_int(va_list lista, t_mastronzo *dado);
int					precision(const char *str, t_mastronzo *dado, size_t i,
						va_list lista);
size_t				ft_strlen(const char *str);
int					mod_atoi(const char *str, t_mastronzo *dado, size_t i,
						int type);
int					width(const char *str, size_t i, t_mastronzo *dado,
						va_list lista);
void				volare(int car, int sing, t_mastronzo *dado);
void				reset(t_mastronzo *dado);

#endif
