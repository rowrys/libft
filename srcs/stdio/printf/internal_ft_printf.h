/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_ft_printf.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:53:42 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/04 16:46:05 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FT_PRINTF_H
# define INTERNAL_FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>

void	ft_printf_putunbr(int fd, unsigned int n, int *count, const char *base);
void	ft_printf_putaddr(int fd, uintptr_t n, int *count, const char *base);
void	ft_printf_putnbr(int fd, int n, int *count);

void	ft_printf_putstr(int fd, const char *str, int *count);
void	ft_printf_putchar(int fd, unsigned char c, int *count);

#endif