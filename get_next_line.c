/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:26:16 by gamorcil          #+#    #+#             */
/*   Updated: 2025/02/24 14:12:00 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char	*line)
{
	char	*left_string;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left_string = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!left_string)
	{
		free(line);
		return (NULL);
	}
	if (*left_string == '\0')
	{
		free(left_string);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (left_string);
}

char	*fill_line_buffer(int fd, char	*left_str, char	*buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_str);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_str)
			left_str = ft_strdup("");
		tmp = left_str;
		left_str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_string;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_string, buffer);
	free(buffer);
	if (!line)
	{
		left_string = NULL;
		return (NULL);
	}
	left_string = set_line(line);
	return (line);
}
