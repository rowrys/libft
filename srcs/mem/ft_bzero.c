/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:28 by mcolin            #+#    #+#             */
/*   Updated: 2025/11/26 16:04:42 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	iter;
	size_t	new_addrs;

	iter = 0;
	while (((size_t)s + iter) & (sizeof(size_t) - 1) && iter < n)
		((char *)s)[iter++] = 0;
	while (iter + sizeof(size_t) - 1 < n)
	{
		new_addrs = (size_t)s + iter;
		*((size_t *)new_addrs) = 0;
		iter += sizeof(size_t);
	}
	while (iter < n)
		((char *)s)[iter++] = 0;
}
