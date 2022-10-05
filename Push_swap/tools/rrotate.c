/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:40:11 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/05 16:59:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

static void
	ft_rrotate_stack(t_stack *stack)
{
	t_elems	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->last;
	stack->last = tmp->back;
	stack->last->next = NULL;
	tmp->next = stack->first;
	tmp->back = NULL;
	stack->first->back = tmp;
	stack->first = tmp;
}

void
	ft_rra(t_stack *a)
{
	if (a->len > 1)
	{
		ft_rrotate_stack(a);
		if (ft_printf("%s", INS_RRA) == ERR_NUM)
			ft_cleanstacks(a, NULL);
	}
}

void
	ft_rrb(t_stack *b)
{
	if (b->len > 1)
	{
		ft_rrotate_stack(b);
		if (ft_printf("%s", INS_RRB) == ERR_NUM)
			ft_cleanstacks(NULL, b);
	}
}

void
	ft_rrr(t_stack *a, t_stack *b)
{
	if (a->len > 1 && b->len > 1)
	{
		ft_rrotate_stack(a);
		ft_rrotate_stack(b);
		if (ft_printf("%s", INS_RRR) == ERR_NUM)
			ft_cleanstacks(a, b);
	}
}
