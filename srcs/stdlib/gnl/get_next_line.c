/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:47:00 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/08 09:47:40 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_get_line(const char *buffer, char *charset)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (!ft_strchr(charset, buffer[i]) && buffer[i])
		i++;
	i += (ft_strchr(charset, buffer[i]) && buffer[i]);
	if (!i)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, i + 1);
	j = 0;
	while (j < i)
	{
		res[j] = buffer[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

static char	get_read_error(ssize_t r, char **buffer)
{
	if (r == 0)
		return (1);
	if (r < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (1);
	}
	return (0);
}

static char	*read_buffer(int fd, char *buffer, char *charset)
{
	char			*new;
	char			*tmp;
	ssize_t			r;

	new = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (NULL);
	while (1)
	{
		ft_bzero(new, BUFFER_SIZE + 1);
		r = read(fd, new, BUFFER_SIZE);
		if (get_read_error(r, &buffer))
			break ;
		tmp = buffer;
		buffer = ft_strjoin(tmp, new);
		free(tmp);
		if (ft_check_chrs(new, charset))
			break ;
	}
	free(new);
	return (buffer);
}

static char	*erase_line(char *buffer, char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (!ft_strchr(charset, buffer[i]) && buffer[i])
		i++;
	i += (ft_strchr(charset, buffer[i]) && buffer[i]);
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = buffer[i + j];
	return (buffer);
}

char	*get_next_line(int fd, char *charset)
{
	static char		*buffer[1024] = {NULL};
	char			*result;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd], charset);
	if (!buffer[fd])
		return (NULL);
	result = ft_get_line(buffer[fd], charset);
	buffer[fd] = erase_line(buffer[fd], charset);
	if (!result || fd <= 2)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (result);
}
