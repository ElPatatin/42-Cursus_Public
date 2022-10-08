/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:05:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/09 00:25:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

void
	ft_sort_three(t_stack *a)
{
	if (!ft_issorted(a->first))
		return ;
	if (a->first->idx == 0)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (a->first->idx == 1 && a->first->next->idx == 0)
		ft_sa(a);
	else if (a->first->idx == 1
		&& a->first->next->idx == 2)
		ft_rra(a);
	if (a->first->idx == 2
		&& a->first->next->idx == 1)
	{
		ft_ra(a);
		ft_sa(a);
	}
	else if (a->first->idx == 2 && a->first->next->idx == 0)
		ft_ra(a);
}

void
	ft_sort_four(t_stack *a, t_stack *b)
{	
	ft_putfirst_a(a, 0);
	if (!ft_issorted(a->first))
		return ;
	ft_pb(a, b);
	ft_indexer(a);
	ft_sort_three(a);
	ft_pa(a, b);
}

void
	ft_sort_five(t_stack *a, t_stack *b)
{
	ft_putfirst_a(a, 0);
	if (!ft_issorted(a->first))
		return ;
	ft_pb(a, b);
	ft_putfirst_a(a, 1);
	ft_pb(a, b);
	ft_indexer(a);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
