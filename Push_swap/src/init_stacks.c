/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:41:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/10 20:56:17 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_elems
	*ft_newnode(int nbr)
{
	t_elems	*new;

	new = (t_elems *)malloc(sizeof(t_elems));
	if (!new)
		return (NULL);
	new->val = nbr;
	new->idx = 0;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

void
	ft_init_stack_a(t_stack *a, int nbr, char **str)
{
	t_elems	*lst;
	t_elems	*tmp;

	a->len = -1;
	a->first = NULL;
	a->last = NULL;
	lst = NULL;
	while (++a->len < nbr - 1)
	{
		lst = ft_newnode(ft_atoi(str[a->len + 1]));
		if (!lst)
			ft_clean_list_creation(a);
		if (!a->last)
		{
			a->first = lst;
			a->last = lst;
			continue ;
		}
		tmp = a->last;
		a->last = lst;
		tmp->next = a->last;
		a->last->back = tmp;
	}
}

void
	ft_init_stack_b(t_stack *b)
{
	b->len = 0;
	b->first = NULL;
	b->last = NULL;
}

void
	ft_indexer(t_stack *stack)
{
	t_elems	*tmp;
	t_elems	*current;
	ssize_t	idx;
	ssize_t	count;

	current = stack->first;
	count = -1;
	while (++count < stack->len)
	{
		idx = 0;
		tmp = stack->first;
		while (tmp)
		{
			if (current->val > tmp->val)
				idx++;
			tmp = tmp->next;
		}
		current->idx = idx;
		current = current->next;
	}
}
