/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:03:53 by gamorcil          #+#    #+#             */
/*   Updated: 2025/02/11 11:13:08 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	if (d == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char	*str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s) + 1;
	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		new[size] = s[size];
		size++;
	}
	new[size] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
