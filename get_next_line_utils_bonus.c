/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:54 by ldiogo            #+#    #+#             */
/*   Updated: 2022/07/28 01:10:57 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	else
	{
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = dest;
	while (len-- > 0)
	{
		*ptr++ = c;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

char	*ft_strndup(char *str)
{
	char	*dest;
	int		i;

	i = -1;
	dest = ft_calloc(ft_strlen(str, 1) + 2, 1);
	if (dest == NULL)
		return (NULL);
	while (++i < ft_strlen(str, 1) + 1)
		dest[i] = str[i];
	return ((char *)dest);
}
