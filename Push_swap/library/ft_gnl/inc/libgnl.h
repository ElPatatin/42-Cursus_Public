/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:11:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:51:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# include "../../libft/inc/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *buff);
char	*ft_read_save(int fd, char *buff);
char	*ft_save(char *buff);

#endif
