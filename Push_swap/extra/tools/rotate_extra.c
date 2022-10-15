/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:40:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/15 10:19:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_extra.h"
#include "../inc/moves_extra.h"

static void
	ft_rotate_stack(t_stack *stack)
{
	t_elems	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->first;
	stack->first = tmp->next;
	stack->first->back = NULL;
	tmp->next = NULL;
	tmp->back = stack->last;
	stack->last->next = tmp;
	stack->last = tmp;
}

int
	ft_ra(t_stack *a)
{
	if (a->len > 1)
	{
		ft_rotate_stack(a);
		return (TRUE);
	}
	return (FALSE);
}

int
	ft_rb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_rotate_stack(b);
		return (TRUE);
	}
	return (FALSE);
}

int
	ft_rr(t_stack *a, t_stack *b)
{
	if (a->len > 1 && b->len > 1)
	{
		ft_rotate_stack(a);
		ft_rotate_stack(b);
		return (TRUE);
	}
	return (FALSE);
}
