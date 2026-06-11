/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:28 by mcolin            #+#    #+#             */
/*   Updated: 2026/06/10 12:51:34 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	size_t			*addrs_sizet;
	unsigned char	*addrs;

	i = 0;
	addrs = (unsigned char *)s;
	while (((size_t)addrs) & (_Alignof(size_t) - 1) && i < n)
	{
		*addrs = 0;
		++addrs;
		++i;
	}
	addrs_sizet = (size_t *)addrs;
	while (i + sizeof(size_t) <= n)
	{
		*addrs_sizet = 0;
		++addrs_sizet;
		i += sizeof(size_t);
	}
	addrs = (unsigned char *)addrs_sizet;
	while (i++ < n)
	{
		*addrs = 0;
		++addrs;
	}
}
