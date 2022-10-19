/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:19:41 by ldiogo            #+#    #+#             */
/*   Updated: 2022/07/28 05:09:15 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrplus(const char *s, int c);
void	*ft_memcpy(void *dest, void *src, size_t len);
char	*ft_strndup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_exstrchr(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

#endif
