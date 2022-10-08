/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:48:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/09 00:24:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

static int	ft_moves_director(t_stack *stack, int nbr, ssize_t *mov);
static void	ft_putfirst_b1_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov);
static void	ft_putfirst_b2_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov);

void
	ft_putfirst_a(t_stack *a, int nbr)
{
	ssize_t	mov;
	ssize_t	rot;
	ssize_t	idx;

	idx = 0;
	mov = 0;
	rot = ft_moves_director(a, nbr, &mov);
	if (rot == ONTOP || rot == ERR_NUM)
		return ;
	if (rot == ROTATE)
		while (++idx <= mov)
			ft_ra(a);
	else if (rot == RROTATE)
		while (++idx <= mov)
			ft_rra(a);
}

void
	ft_putfirst_b(int nbr, t_stack *a, t_stack *b)
{
	ssize_t	mov;
	ssize_t	rot;

	mov = 0;
	rot = ft_moves_director(b, nbr, &mov);
	if (rot == ONTOP || rot == ERR_NUM)
		return ;
	if (rot == ROTATE)
		ft_putfirst_b1_aux(a, b, nbr, mov);
	if (rot == RROTATE)
		ft_putfirst_b2_aux(a, b, nbr, mov);
}

static void
	ft_putfirst_b1_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov)
{
	ssize_t	idx;

	idx = 0;
	while (++idx <= mov)
	{
		if (b->first->idx == (nbr - 1))
			ft_pa(a, b);
		else if (b->first->idx == (nbr - 2))
		{
			ft_pa(a, b);
			ft_ra(a);
		}
		else
			ft_rb(b);
	}
}

static void
	ft_putfirst_b2_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov)
{
	ssize_t	idx;

	idx = 0;
	while (++idx <= mov)
	{
		if (b->first->idx == (nbr - 1))
		{
			ft_pa(a, b);
			mov++;
		}
		else if (b->first->idx == (nbr - 2))
		{
			ft_pa(a, b);
			ft_ra(a);
			mov++;
		}
		else
			ft_rrb(b);
	}
}

static int
	ft_moves_director(t_stack *stack, int nbr, ssize_t *mov)
{
	t_elems	*first;
	ssize_t	pos;
	ssize_t	half;

	first = stack->first;
	pos = 0;
	half = stack->len / 2;
	pos = ft_check_first(first, pos, nbr);
	if (pos == 0)
		return (ONTOP);
	else if (pos < half)
	{
		*mov = pos;
		return (ROTATE);
	}
	else if (pos >= half)
	{
		*mov = stack->len - pos;
		return (RROTATE);
	}
	return (ERR_NUM);
}
