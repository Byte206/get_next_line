/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:24:44 by gamorcil          #+#    #+#             */
/*   Updated: 2025/11/22 19:31:35 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char    *get_next_line(int fd)
{
    static char *left_string[1024];
    char        *line;
    char        *buffer;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)  // Añade límite superior
        return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    line = fill_line_buffer(fd, left_string[fd], buffer);
    free(buffer);
    if (!line)
    {
        free(left_string[fd]);  // Libera la memoria antes
        left_string[fd] = NULL;
        return (NULL);
    }
    left_string[fd] = set_line(line);
    return (line);
}
#include <stdio.h>

int main()
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	char *line1;
	char *line2;

	while (line1 || line2)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1)
		{
			printf("File 1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("File 2: %s", line2);
			free(line2);
		}
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}

	close(fd1);
	close(fd2);
	return 0;
}