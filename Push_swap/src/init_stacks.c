/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:41:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 09:42:58 by cpeset-c         ###   ########.fr       */
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
		ft_check_node(lst, a);
		if (!a->last)
		{
			a->first = lst;
			a->last = lst;
		}
		else
		{
			tmp = a->last;
			a->last = lst;
			tmp->next = a->last;
			a->last->back = tmp;
		}
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
	ssize_t	idx1;
	ssize_t	idx2;

	current = stack->first;
	idx2 = -1;
	while (++idx2 < stack->len)
	{
		idx1 = 0;
		tmp = stack->first;
		while (tmp)
		{
			if (tmp->val < current->val)
				idx1++;
			tmp = tmp->next;
		}
		current->idx = idx1;
		current = current->next;
	}
}
