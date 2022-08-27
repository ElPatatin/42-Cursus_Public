/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:08:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 18:20:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_H
# define LIB_FT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <sys/wait.h>

# define TURE   (int)0
# define FALSE  (int)1

typedef unsigned long long	t_unll;
typedef int					t_bool;
typedef unsigned long		t_ul;
typedef long long			t_ll;
typedef unsigned int		t_unt;

// FT_is functions. Return 1 if true, return 0 if false
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);

// FT_math functions. Multiple purpouse functions for operations.
t_ll	ft_pow(t_ll n, t_unt pow);
t_ll	ft_factorial(t_ll nb);
int		ft_sqrt(int nb);
int		ft_prime(int nb);
t_unt	ft_lcm(t_unt a, t_unt b);
int		ft_find_next_prime(int nb);
t_ll	ft_absval(t_ll n);
int		ft_nbrlen(int nbr);
int		ft_nbrlen_base(t_ll nbr, int base);
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, int base);
char	*ft_itoa(int nbr);
char	*ft_itoa_base(int nbr, int base);

// FT_mem functions.
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dsy, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		*ft_range(int min, int max);
int		*ft_rrange(int start, int end);
int		ft_ultrange(int **range, int min, int max);
char	**ft_memfree(char **ptr, int len);

// FT_put functions. These functions prints either in standart output or in fd
int		ft_putchar(int c);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr(char	*str);
int		ft_putstr_fd(char	*str, int fd);
int		ft_putnbr(t_ll nbr);
int		ft_putnbr_fd(t_ll nbr, int fd);
int		ft_putnbr_base_fd(t_ll nbr, int base, int fd);

// Ft_sort functions. Sorting purpouse functions
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, unsigned int size);
void	ft_rev_int_tab(int *tab, int size);
void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int lenght, int (*f)(int));
int		ft_any(char **tab, int (*f)(char *));
int		ft_count_if(char **tab, int lenght, int (*f)(char *));
void	ft_sort_str_tab(char **tab);
void	ft_adv_sort_str_tab(char **tab, int (*cmp)(char *, char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

// FT_str functions. Multiple functions about strings manipulation or related.
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
int		ft_str_wcount(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dst, char *src);
size_t	ft_strlcpy(char *dst, const char *src, ssize_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strcspn(const char *s, const char *reject);
char	*ft_strcapitalize(char *str);
char	*ft_strlowcase(char	*str);
char	*ft_strupcase(char	*str);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
