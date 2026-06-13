/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:40:13 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/13 18:22:13 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_ft_printf.h"

#include <stdarg.h>
#include <stdint.h>

#define HEX_MAJ "0123456789ABCDEF"
#define HEX_MIN "0123456789abcdef"

static void	get_format(int fd, const char fmt, va_list *va, int *count)
{
	if (fmt == 'd' || fmt == 'i')
		ft_printf_putnbr(fd, va_arg(*va, int), count);
	else if (fmt == 's')
		ft_printf_putstr(fd, va_arg(*va, const char *), count);
	else if (fmt == 'c')
		ft_printf_putchar(fd, (unsigned char)va_arg(*va, int), count);
	else if (fmt == 'u')
		ft_printf_putunbr(fd, va_arg(*va, unsigned int), count, "0123456789");
	else if (fmt == 'x')
		ft_printf_putunbr(fd, va_arg(*va, unsigned int), count, HEX_MIN);
	else if (fmt == 'X')
		ft_printf_putunbr(fd, va_arg(*va, unsigned int), count, HEX_MAJ);
	else if (fmt == 'p')
		ft_printf_putaddr(fd, (uintptr_t)va_arg(*va, void *), count, HEX_MIN);
	else if (fmt == '%')
		ft_printf_putchar(fd, '%', count);
	else
	{
		ft_printf_putchar(fd, '%', count);
		ft_printf_putchar(fd, fmt, count);
	}
}

static inline int	print_str(int fd, const char *fmt, size_t *i, size_t *j)
{
	int		count;

	write(fd, fmt + *j, *i - *j);
	count = *i - *j;
	*j = *i;
	if (fmt[*i] == '%')
		*j += 2;
	return (count);
}

static int	ft_printf_base(int fd, const char *fmt, va_list *va)
{
	size_t	i;
	size_t	j;
	int		count;

	if (!fmt)
		return (-1);
	i = 0;
	j = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			count += print_str(fd, fmt, &i, &j);
			get_format(fd, fmt[i + 1], va, &count);
			i += 2;
		}
		else
			i++;
	}
	if (i != j)
		count += print_str(fd, fmt, &i, &j);
	return (count);
}

int	ft_printfd(int fd, const char *fmt, ...)
{
	va_list	va;
	int		count;

	va_start(va, fmt);
	count = ft_printf_base(fd, fmt, &va);
	va_end(va);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	va;
	int		count;

	va_start(va, fmt);
	count = ft_printf_base(1, fmt, &va);
	va_end(va);
	return (count);
}
