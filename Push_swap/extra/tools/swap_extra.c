/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:40:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/15 10:19:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_extra.h"
#include "../inc/moves_extra.h"

static void
	ft_stack_swap(t_stack *stack)
{
	t_elems	*tmp;
	int		tmpnbr;

	tmp = stack->first->next;
	if (stack->len == 2)
	{
		tmpnbr = stack->first->val;
		stack->first->val = stack->first->next->val;
		stack->first->next->val = tmpnbr;
	}
	else if (stack->len > 2)
	{
		stack->first->next->next->back = stack->first;
		stack->first->next = stack->first->next->next;
		tmp->next = stack->first;
		tmp->back = NULL;
		stack->first->back = tmp;
		stack->first = tmp;
	}
}

int
	ft_sa(t_stack *a)
{
	if (a->len > 1)
	{
		ft_stack_swap(a);
		return (TRUE);
	}
	return (FALSE);
}

int
	ft_sb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_stack_swap(b);
		return (TRUE);
	}
	return (FALSE);
}

int
	ft_ss(t_stack *a, t_stack *b)
{
	if (a->len > 1 && b->len > 1)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
		return (TRUE);
	}
	return (FALSE);
}
