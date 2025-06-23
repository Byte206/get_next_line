/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:01:22 by gamorcil          #+#    #+#             */
/*   Updated: 2025/02/11 12:47:39 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_line(int fd, char *left_c, char *buffer);
char	*set_line(char	*lie_buffer);
void	*ft_memcpy(void *dest, const void *src, size_t n);
//utils
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char	*s);
char	*ft_substr(char	const *s, unsigned int start, size_t	len);

#endif
