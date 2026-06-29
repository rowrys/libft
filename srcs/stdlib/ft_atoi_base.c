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
	return (c == '+' || c == '-' || (unsigned char)(c) - 9 <= 13);
}

static bool	init_buffer(unsigned char *buffer, unsigned char const *base)
{
	size_t	i;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	i = 0;
	while (base[i])
	{
		if (buffer[(int)base[i]] != 0 || is_invalid_char(base[i]))
			return (1);
		buffer[(int)base[i]] = i + 1;
		++i;
	}
	return (0);
}

// thanks norm...
static char const	*get_sign(char const *str, int8_t *sign)
{
	while (*str == ' ' || (unsigned char)(*str) - 9 <= 13)
		++str;
	*sign = 1;
	if (*str == '-')
		*sign = -(*sign);
	if (*str == '+' || *str == '-')
		++str;
	return (str);
}

int	ft_atoi_base(char const *str, char const *base, bool *of_flag)
{
	size_t			i;
	int				result;
	size_t			base_len;
	int8_t			sign;
	unsigned char	buffer[BUFFER_SIZE + 1];

	if (init_buffer(buffer, (unsigned char *)base))
		return (0);
	str = get_sign(str, &sign);
	result = 0;
	i = 0;
	base_len = ft_strlen(base);
	if (of_flag)
		*of_flag = 0;
	while (str[i])
	{
		if (!buffer[(int)(unsigned char)str[i]])
			return (0);
		if (of_flag && result > (int)(result * base_len)
			+ buffer[(int)(unsigned char)str[i]])
			*of_flag = 1;
		result = (result * base_len) + (buffer[(int)(unsigned char)str[i++]] - 1);
	}
	return (result * sign);
}
