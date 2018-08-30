/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:25:46 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 17:18:01 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"


int					ft_print(const char *str, va_list *ap, int print);
int					ft_printf(const char *format, ...);

enum				e_mod
{
	nomod,
	l,
	ll,
	h,
	hh,
	j,
	z
};

enum				e_conv
{
	c,
	C,
	d,
	o,
	p,
	s,
	S,
	u,
	x,
	X,
	pct,
	ch,
	b,
};

typedef struct		s_flag
{
	int				hash;
	int				zero;
	int				min;
	int				sp;
	int				plus;
	int				width;
	int				prc;
	int				prc_len;
	int				ret;
	int				sign;
	enum e_mod		mod;
	enum e_conv		conv;
	char			c;
}					t_flag;

char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *s);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_free(const char *s1, const char *s2, int free);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
char				*ft_itoa(intmax_t c);
char				*ft_u_itoa(uintmax_t c);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr(const char *s);
void				ft_putnstr(const char *s, int len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_itoa_base(uintmax_t n, int base);
char				*ft_itoa_base_2(uintmax_t n, int base);
char				*ft_itoa_bin(uintmax_t n, int flag);
char				*ft_itoa_oct(uintmax_t n, int flag);
char				*ft_char_to_str(char c);
char				*ft_wc_to_str(wchar_t c);

char				*ft_find_flags(char **str, t_flag *flag);
char				*ft_find_width(char **str, t_flag *flag, va_list *ap);
char				*ft_find_prc(char **str, t_flag *flag, va_list *ap);
char				*ft_find_mod(char **str, t_flag *flag);
char				*ft_find_conversion(char **str, t_flag *flag);
int					ft_print_opt(int len, int opt, char c);

intmax_t			ft_print_signed(t_flag *flag, intmax_t nb);
uintmax_t			ft_print_unsigned(t_flag *flag, uintmax_t nb);
int					ft_print_char(va_list *ap, t_flag *flag);
int					ft_print_ch(va_list *ap, t_flag *flag);
int					ft_print_pct(va_list *ap, t_flag *flag);
void				ft_print_prc(char **str, char *sign, int *len, t_flag *f);
void				ft_print_u_prc(char **str, size_t *len, t_flag *f);
int					ft_print_int(va_list *ap, t_flag *flag);
int					ft_print_u_int(va_list *ap, t_flag *flag);
int					ft_print_str(va_list *ap, t_flag *flag);
int					ft_print_octal(va_list *ap, t_flag *flag);
int					ft_print_hexa(va_list *ap, t_flag *flag);
int					ft_print_hexa2(va_list *ap, t_flag *flag);
int					ft_print_ptr(va_list *ap, t_flag *flag);
int					ft_print_bin(va_list *ap, t_flag *flag);
int					ft_print_wchar(va_list *ap, t_flag *flag);
int					ft_print_wstr(va_list *ap, t_flag *flag);

#endif
