/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:08:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/08 18:38:42 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1
# endif

# define TRUE	(int)1
# define FALSE	(int)0
# define UNUSED	(void)

typedef int					t_bool;
typedef unsigned int		t_unt;
typedef long long			t_ll;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef struct s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

// FT_GNL funtion. The get next line 42 project.
char	*get_next_line(int fd);

// FT_is functions. Return 1 if true, return 0 if false
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

// FT_math functions. Multiple purpouse functions for operations.
t_ll	ft_pow(t_ll n, t_unt pow);
t_ll	ft_factorial(t_ll nb);
int		ft_sqrt(int nb);
int		ft_prime(int nb);
t_unt	ft_lcm(t_unt a, t_unt b);
int		ft_find_next_prime(int nb);
t_ll	ft_absval(t_ll n);
int		ft_nbrlen(t_ll nbr);
int		ft_nbrlen_base(t_ll nbr, int base);
t_unt	ft_unbrlen_base(t_ull nbr, int base);
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, char *str_base);
t_ll	ft_atoll_base(const char *str, char *str_base);
char	*ft_itoa(int nbr);
char	*ft_itoa_base(int nbr, char *str_base);
char	*ft_lltoa_base(t_ll nbr, char *str_base);
char	*ft_ulltoa_base(t_ull nbr, char *str_base);
t_ll	ft_stou(t_ll nbr);
t_ull	ft_stoul(t_ull nbr);

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
char	*ft_substr(const char *s, unsigned int start, size_t len);
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

// FT_list functions. Recopilation of libft and piscine list functions.
t_list	*ft_lstnew(void *data);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *begin_list);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstpush_front(t_list **begin_list, void *data);
void	ft_lstpush_back(t_list **begin_list, void *data);
t_list	*ft_lstpush_strs(int size, char **strs);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *));
t_list	*ft_lstat(t_list *begin_list, t_unt nbr);
void	ft_lstreverse(t_list **begin_list);
void	ft_lstreverse_fun(t_list *begin_list);
void	ft_lstforeach(t_list *begin_list, void (*f)(void *));
void	ft_lstforeach_if(t_list *begin_list, void (*f)(void *),
			void *data_ref, int (*cmp)());
t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)());
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstswap(t_list *a, t_list *b);
void	ft_lstsort(t_list **begin_list, int (*cmp)());
void	ft_lstsort_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void	ft_lstmerge_sort(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)());

#endif
