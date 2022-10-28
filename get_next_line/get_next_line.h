/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:21:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/23 20:47:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1
# endif

// GNL Principal Function
char	*get_next_line(int fd);

// GNL Functions
char	*ft_read_line(int fd, char *buff);
char	*ft_get_line(char *buff);
char	*ft_save_line(char *buff);
void	*ft_clean_line(char **line);

// GNL Util Functions
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	*ft_calloc(size_t size);

#endif
