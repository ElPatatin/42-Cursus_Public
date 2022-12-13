/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 17:34:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_data_structures.h"
# include "../library/inc/libft.h"
# include <stdarg.h>

// Function Reference
# define FTRREF		(char *)"%cspdiuxX"

// Hexadecimal Prefix Direction
# define HEXPRE		(char *)"0x"
# define HEXPREU	(char *)"0X"

// ERROR VALS
# define ERRNUM		(int)-1
# define NLLMSG		(char *)"(null)"

// SIGN FLAGS
# define PLSSIGN	(int)1
# define MNSSIGN	(int)2
# define SPCSIGN	(int)3

// BASE VALS
# define STR_BASE10		(char *)"0123456789"
# define STR_BASE16L	(char *)"0123456789abcdef"
# define STR_BASE16U	(char *)"0123456789ABCDEF"

// ft_printf function
int		ft_printf(const char *fmt, ...);

// Error Control Functions
void	err_check(t_vars *vars, t_flags *flags);
void	err_print(t_vars *vars);
void	err_width(t_vars *vars, t_flags *flags);
void	err_margin(t_vars *vars, t_flags *flags);
void	err_hex_preffix(t_vars *vars, t_flags *flags);

// Parser Function
int		ft_parse_params(t_vars *vars, t_flags *flags);
int		get_params(t_vars *vars, t_flags *flags);
int		ft_check(t_vars *vars, t_flags *flags);

// Init Param
t_vars	init_vars(const char *fmt);
t_flags	init_flags(void);
int		get_flags(t_vars *vars, t_flags *flags);

// Utils Printf
int		input_check(char c);
ssize_t	ft_clean_str(char **str);
t_ll	aux_check_param_zeros(t_vars *vars, t_flags *flags, char c, t_ll len);
ssize_t	print_hex_prefix(t_vars *vars, t_flags *flags);

// Char Utils Printf
ssize_t	print_char(unsigned char c);
ssize_t	print_string(char *str);

// Number Utils Printf
ssize_t	print_ptr(t_ull nbr, t_vars *vars, t_flags *flags);
ssize_t	print_nbr(t_ll nbr, t_vars *vars, t_flags *flags);
ssize_t	print_hex(t_ll nbr, t_vars *vars, t_flags *flags);

// Margin Utils
ssize_t	add_width(t_vars *vars, t_flags *flags);
ssize_t	add_zeros(t_vars *varst, t_flags *flags);

#endif