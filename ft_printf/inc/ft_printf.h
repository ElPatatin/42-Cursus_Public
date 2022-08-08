/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:46:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/12 10:52:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

# define TRUE	(int)1;
# define FALSE	(int)0;

typedef unsigned int		t_unt;
typedef unsigned long long	t_unll;

typedef struct s_vars
{
	ssize_t	idx;
	ssize_t	bytes;
	char	c;
	va_list	args;
}			t_vars;

int	ft_printf(const char *fmt, ...);

int	ft_char(int c);
int	ft_string(char *str);
int	ft_nbrbase(int n, int base, char c);
int	ft_vptr(t_unll arg);

#endif
