/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:47:00 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/08 09:47:40 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdint.h>
#include <limits.h>

#define BUFFER_SIZE UCHAR_MAX

static inline bool	is_invalid_char(const char c)
{
	return (c == '+' || c == '-' || (9 <= c && c <= 13));
}

static bool	init_buffer(unsigned char *buffer, char const *base)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = 255;
	i = 0;
	while (base[i])
	{
		if (buffer[(int)base[i]] != 255 || is_invalid_char(base[i]))
			return (1);
		buffer[(int)base[i]] = i;
		++i;
	}
	return (0);
}

int	ft_atoi_base(char const *str, char const *base, bool *of_flag)
{
	size_t			i;
	size_t			base_len;
	int				result;
	int8_t			sign;
	unsigned char	buffer[BUFFER_SIZE + 1];

	if (init_buffer(buffer, base))
		return (0);
	while (*str == ' ' || (unsigned char)(*str) - 9 <= 13)
		++str;
	sign = 1 - (2 * (*str == '-'));
	if (*str == '+' || *str == '-')
		++str;
	i = 0;
	base_len = ft_strlen(base);
	if (of_flag)
		*of_flag = 0;
	while (str[i])
	{
		if (of_flag && result > (int)(result * base_len) + buffer[(int)str[i]])
			*of_flag = 1;
		result = (result * base_len) + buffer[(int)str[i++]];
	}
	return (result * sign);
}
