/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:01:11 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/05 16:13:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"
#include "../inc/moves_bonus.h"

int
	ft_issorted(t_elems *lst)
{
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int
	ft_check_maxint(t_ll nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

void
	ft_check_node(t_elems *lst, t_stack *stack)
{
	if (!lst)
		ft_stackclear(stack);
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
