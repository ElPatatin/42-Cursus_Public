/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:13:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 10:20:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

static void	ft_sort_aux(t_stack *a, t_stack *b, int cut);
static void	ft_at_b_stack(t_stack *b, int idx, int cut);
static void	ft_backto_a(t_stack *a, t_stack *b);

void
	ft_sort_bigger(t_stack *a, t_stack *b, int chunks)
{
	int	idx;
	int	count;
	int	cut;

	count = 0;
	cut = a->len / chunks;
	while (++count < chunks)
	{
		idx = 0;
		while (idx < cut)
		{
			if (a->first->idx < cut)
			{
				ft_pb(a, b);
				ft_at_b_stack(b, b->first->idx, cut);
				idx++;
			}
			else
				ft_ra(a);
		}
		ft_indexer(a);
	}
	ft_sort_aux(a, b, cut);
}

static void
	ft_sort_aux(t_stack *a, t_stack *b, int cut)
{
	while (a->len)
	{
		ft_pb(a, b);
		ft_at_b_stack(b, b->first->idx, cut);
	}
	ft_indexer(b);
	ft_backto_a(a, b);
}

static void
	ft_backto_a(t_stack *a, t_stack *b)
{
	while (b->len)
	{
		ft_putfirst_b(ft_get_maxidx(b), a, b);
		ft_pa(a, b);
		if (a->len > 2 && a->first->idx != 0
			&& a->first->next->idx == (a->first->idx - 1))
			ft_sa(a);
		if (a->len > 1 && a->first->idx != 0
			&& a->last->idx < a->last->back->idx)
			ft_rra(a);
	}
}

static void
	ft_at_b_stack(t_stack *b, int idx, int cut)
{
	if (idx < cut / 2)
		ft_rb(b);
}
