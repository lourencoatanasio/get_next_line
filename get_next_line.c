/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:52 by ldiogo            #+#    #+#             */
/*   Updated: 2022/10/19 15:10:41 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_exstrchr(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	tmp = malloc((ft_strlen(s, 0) - i) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s + i + 1, ft_strlen(s, 0) - i + 1);
	free(s);
	return (tmp);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	else if (!size)
		return (ft_strlen(src, 0));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src, 0));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_nl(int fd, char *buffer, char *line)
{
	int		i;
	char	*cpy;

	i = 1;
	while (!(ft_strchr(line, '\n')) && i)
	{
		cpy = line;
		i = read (fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		line = ft_strjoin(cpy, buffer);
		free(cpy);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*rtn;
	char		*buffer;

	if (read(fd, 0, 0) == -1)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof (char) * 1);
		line[0] = '\0';
	}
	rtn = NULL;
	buffer = malloc(sizeof (char) * BUFFER_SIZE + 1);
	line = get_nl(fd, buffer, line);
	if (!buffer)
		return (NULL);
	free (buffer);
	if (line[0] == '\0')
		return (NULL);
	rtn = ft_strndup (line);
	line = ft_exstrchr (line);
	return (rtn);
}
