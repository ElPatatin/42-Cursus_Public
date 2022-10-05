/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:01:11 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/02 15:52:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

int
	ft_issorted(t_elems *lst)
{
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int
	ft_check_maxint(t_ll nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int
	ft_while_isdigit(char *str)
{
	if ((str[1] && str[0] == '-')
		|| (str[1] && str[0] == '+'))
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void
	ft_check_node(t_elems *lst, t_stack *stack)
{
	if (!lst)
		ft_stackclear(stack);
}

ssize_t
	ft_check_first(t_elems *first, ssize_t pos, int nbr)
{
	while (first)
	{
		if (first->idx == nbr)
			break ;
		++pos;
		first = first->next;
	}
	return (pos);
}
