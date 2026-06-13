/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:42:24 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/21 21:54:46 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

char	*get_next_line(int fd, char *charset);
ssize_t	get_number_line_file(const char *file_path, char *charset);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
