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

# define ERR_NUM	(int)-1
# define NLL_MSG	(char *)"(null)"

# define BASE10		(char *)"0123456789"
# define BASE16L	(char *)"0123456789abcdef"
# define BASE16U	(char *)"0123456789ABCDEF"

typedef struct s_flags
{
	t_unt	minus;
	t_unt	zero;
	t_unt	dot;
	t_unt	hastag;
	t_unt	space;
	t_unt	plus;
}			t_flags;

typedef struct s_vars
{
	ssize_t	idx;
	ssize_t	bytes;
	char	*str;
	t_unt	fcount;
	char	c;
	va_list	args;
}			t_vars;

// Función principal del printf
int	ft_printf(const char *fmt, ...);

// Funciones auxiliares del printf -> dirigen las inputs y las flags.
int	ft_check(t_vars *vars);
int	ft_print_check(t_vars *vars);
int	ft_get_vars(t_vars *vars, t_flags *flags);

// Utilidades del printf
int	ft_char(int c);
int	ft_string(char *str);
int	ft_nbrbase(int n, int base, char c);
int	ft_vptr(t_unll arg);

// Utilidades bonus del printf
void ft_width(t_vars *vars,  t_flags *flags);

#endif