/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:08:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:40:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H

# include "../../libft/inc/libft.h"

typedef struct s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

t_list	*ft_lstnew(void *data);
t_list	*ft_lstnew_elt(void *data);
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
