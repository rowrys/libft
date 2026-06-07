/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:13:40 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/04 14:15:28 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	iter;
	size_t	j;
	size_t	big_c;
	size_t	new_addrs;

	iter = 0;
	while (((size_t)s + iter) & (sizeof(size_t) - 1) && iter < n)
		((char *)s)[iter++] = c;
	j = sizeof(size_t) - 1;
	big_c = (unsigned char)c;
	while (j)
	{
		big_c <<= 8;
		big_c |= (unsigned char)c;
		j--;
	}
	while (iter + sizeof(size_t) - 1 < n)
	{
		new_addrs = (size_t)s + iter;
		*((size_t *)new_addrs) = big_c;
		iter += sizeof(size_t);
	}
	while (iter < n)
		((char *)s)[iter++] = c;
	return (s);
}
