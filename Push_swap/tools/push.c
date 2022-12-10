/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:40:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/10 20:57:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

static void
	ft_push_src(t_stack *src, t_elems *tmp)
{
	if (src->len > 1)
	{
		src->first = tmp->next;
		src->first->back = NULL;
	}
	else
	{
		src->first = NULL;
		src->last = NULL;
	}
}

static void
	ft_push_dst(t_stack *dst, t_elems *tmp)
{
	if (dst->len < 1)
	{
		dst->first = tmp;
		dst->last = tmp;
		tmp->next = NULL;
		tmp->back = NULL;
	}
	else
	{
		tmp->next = dst->first;
		dst->first->back = tmp;
		dst->first = tmp;
	}
}

static void
	ft_stack_push(t_stack *dst, t_stack *src)
{
	t_elems	*tmp;

	tmp = src->first;
	ft_push_src(src, tmp);
	ft_push_dst(dst, tmp);
	++dst->len;
	--src->len;
}

void
	ft_pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	ft_stack_push(a, b);
	if (ft_printf("%s", INS_PA) == ERR_NUM)
		ft_clean_stacks(a, b);
}

void
	ft_pb(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return ;
	ft_stack_push(b, a);
	if (ft_printf("%s", INS_PB) == ERR_NUM)
		ft_clean_stacks(a, b);
}
