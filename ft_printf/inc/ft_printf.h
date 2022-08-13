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
# include "../libft/inc/lib_ft.h"

typedef struct s_vars
{
	ssize_t	idx;
	ssize_t	bytes;
	char	*str;
	t_unt	i;
	t_unt	minus;
	t_unt	zero;
	t_unt	dot;
	t_unt	hastag;
	t_unt	space;
	t_unt	plus;
	t_unt	width;
	t_unt	fcount;
	char	c;
	va_list	args;
}			t_vars;

int	ft_printf(const char *fmt, ...);
int	ft_check(t_vars *vars);
int	ft_print_check(t_vars *vars);

int	ft_char(int c);
int	ft_string(char *str);
int	ft_nbrbase(int n, int base, char c);
int	ft_vptr(t_unll arg);

void ft_width(t_vars *vars);

#endif