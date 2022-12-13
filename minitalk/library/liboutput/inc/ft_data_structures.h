/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_structures.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:16:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 17:21:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_STRUCTURES_H
# define FT_DATA_STRUCTURES_H

# include <stdarg.h>
# include <unistd.h>

typedef int				t_bool;
typedef long long		t_ll;
typedef struct s_vars	t_vars;
typedef struct s_flags	t_flags;

struct s_vars
{
	int		fd;
	int		ref;
	char	c;
	ssize_t	idx;
	ssize_t	count;
	ssize_t	errchk;
	ssize_t	bytes;
	char	*str;
	t_ll	nbr;
	t_ll	prs;
	va_list	args;
	va_list	copy;

};

struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	space;
	t_bool	plus;
	t_bool	sign;
	t_bool	hexpreffix;
};

#endif