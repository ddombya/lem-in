/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:31:54 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:41:39 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_wc_to_str(wchar_t c)
{
	char *s;

	s = ft_strnew(0);
	if (c <= 0x7F)
		s = ft_strjoin(s, ft_char_to_str(c));
	else if (c <= 0x7FF)
	{
		s = ft_strjoin_free(s, ft_char_to_str((c >> 6) + 0xC0), 3);
		s = ft_strjoin_free(s, ft_char_to_str((c & 0x3F) + 0x80), 3);
	}
	else if (c <= 0xFFFF)
	{
		s = ft_strjoin_free(s, ft_char_to_str((c >> 12) + 0xE0), 3);
		s = ft_strjoin_free(s, ft_char_to_str(((c >> 6) & 0x3F) + 0x80), 3);
		s = ft_strjoin_free(s, ft_char_to_str((c & 0x3F) + 0x80), 3);
	}
	else if (c <= 0x10FFFF)
	{
		s = ft_strjoin_free(s, ft_char_to_str((c >> 18) + 0xF0), 3);
		s = ft_strjoin_free(s, ft_char_to_str(((c >> 12) & 0x3F) + 0x80), 3);
		s = ft_strjoin_free(s, ft_char_to_str(((c >> 6) & 0x3F) + 0x80), 3);
		s = ft_strjoin_free(s, ft_char_to_str((c & 0x3F) + 0x80), 3);
	}
	return (s);
}
