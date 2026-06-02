/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:18:18 by mcolin            #+#    #+#             */
/*   Updated: 2026/04/12 15:54:26 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static unsigned char	get_itoa_len(int nb)
{
	unsigned char	res;

	res = 0;
	if (nb < 0)
		res++;
	while (nb)
	{
		res++;
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa_buffer(int n, char *buffer, size_t buffer_size)
{
	unsigned char	i;

	i = get_itoa_len(n);
	if (!buffer || (size_t)i + 1 >= buffer_size)
		return (NULL);
	if (!n)
		return (ft_strcpy(buffer, "0"));
	else if (n == -2147483648)
		return (ft_strcpy(buffer, "-2147483648"));
	if (n < 0)
		n = -n;
	buffer[i--] = '\0';
	while (n)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (!i)
		buffer[i] = '-';
	return (buffer);
}
