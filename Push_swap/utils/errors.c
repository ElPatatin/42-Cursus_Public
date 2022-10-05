/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:18:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/06 00:43:28 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void
	ft_stackclear(t_stack *stack)
{
	t_elems	*tmp;

	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack = NULL;
}

void
	ft_cleanstacks(t_stack *a, t_stack *b)
{
	if (a != NULL)
		ft_stackclear(a);
	if (b != NULL)
		ft_stackclear(b);
	ft_error(ERRCODE3);
}

void
	ft_error(int num)
{
	if (num == ERRCODE0)
		write(2, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (num == ERRCODE1)
		write(2, ERR_MSG1, ft_strlen(ERR_MSG1));
	else if (num == ERRCODE2)
		write(2, ERR_MSG2, ft_strlen(ERR_MSG2));
	else if (num == ERRCODE3)
		write(2, ERR_MSG3, ft_strlen(ERR_MSG3));
	exit(EXIT_FAILURE);
}