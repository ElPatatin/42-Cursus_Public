/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:09 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/05 12:54:25 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE	(int)1
# define FALSE	(int)0
# define UNUSED	(void)

# define ERRSTR	(char *)"Error"

typedef int					t_bool;
typedef unsigned int		t_unt;
typedef unsigned long long	t_ull;
typedef long long			t_ll;

// ft_is functions
t_bool	ft_isupper(int c);
t_bool	ft_islower(int c);
t_bool	ft_isalpha(int c);
t_bool	ft_isdigit(int c);
t_bool	ft_isalnum(int c);
t_bool	ft_isprint(int c);
t_bool	ft_isspace(int c);
t_bool	ft_issign(int c);
t_bool	ft_isascii(int c);
t_bool	ft_ischrinstr(char *str);

// ft_math function
t_ll	ft_absval(t_ll n);
t_ll	ft_nbrlen(t_ll nbr, int base);
t_unt	ft_unbrlen(t_ull nbr, int base);
t_ll	ft_atoll(const char *str, int base);
char	*ft_lltoa(t_ll nbr, char *str);
char	*ft_ulltoa(t_ull nbr, char *str);
t_ll	ft_stou(t_ll nbr);
t_ll	ft_stoul(t_ll nbr);

// ft_mem functions
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

// ft_str functions
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, t_unt start, size_t len);

#endif