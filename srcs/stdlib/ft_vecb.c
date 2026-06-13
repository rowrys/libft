/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:55:29 by mcolin            #+#    #+#             */
/*   Updated: 2026/06/13 11:39:52 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief this fonction return the size you need to alloc to use an vecb.
 * 
 * @param size numbers of bool to store.
 * @return size_t how many byte(s) you need to allocate.
 */
size_t	new_vecb_size(size_t size)
{
	return ((size >> 3) + ((size & 7) != 0));
}

/**
 * @brief this fonction create an array of bool using bit and not byte.
 * 
 * @param size number of bool to store.
 * @return void* address of the array.
 */
void	*vecb(size_t size)
{
	return (malloc(new_vecb_size(size)));
}

static inline unsigned char	bit_pos_to_value(unsigned char bit_pos)
{
	return (1 << bit_pos);
}

/**
 * @brief set an value to vecb array.
 * 
 * @param vecb adress of vecb.
 * @param pos where we set the value in vecb.
 * @param state set in vecb[pos] = state
 */
void	vecb_set(void *vecb, size_t pos, unsigned char state)
{
	if (state)
		((unsigned char *)vecb)[pos >> 3] |= bit_pos_to_value(pos & 7);
	else
		((unsigned char *)vecb)[pos >> 3] &= ~bit_pos_to_value(pos & 7);
}

/**
 * @brief get an value to vecb array.
 * 
 * @param vecb adress of vecb.
 * @param pos where we get the value in vecb.
 */
bool	vecb_get(void *vecb, size_t pos)
{
	return (((unsigned char *)vecb)[pos >> 3] & bit_pos_to_value(pos & 7));
}
