/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_chrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:46:52 by mcolin            #+#    #+#             */
/*   Updated: 2026/04/15 11:26:53 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_check_chrs(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]))
			return (1);
		i++;
	}
	return (0);
}
