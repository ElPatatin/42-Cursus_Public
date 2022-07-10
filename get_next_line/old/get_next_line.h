/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:21:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/11 11:35:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// Macros para el header
// BORRAR MAS TARDE
# define NOARG			(char *)"File name missing.\n"
# define TMARG			(char *)"Too many arguments.\n"
# define NOREAD			(char *)"Cannot read file.\n"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

char	*get_next_line(int fd);
char	*ft_linealloc(int fd, char *tmpbuff, char *buffer);
int		ft_buffln(char *buff, int size);

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t size);

#endif
