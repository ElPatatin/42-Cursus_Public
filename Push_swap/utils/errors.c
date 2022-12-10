/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:18:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/10 20:57:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void
	ft_stack_clear(t_stack *stack)
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
	ft_clean_stacks(t_stack *a, t_stack *b)
{
	if (a != NULL)
		ft_stack_clear(a);
	if (b != NULL)
		ft_stack_clear(b);
	ft_error(ERRCODE3);
}

void
	ft_clean_list_creation(t_stack *a)
{
	ft_stack_clear(a);
	ft_error(ERRCODE2);
}

void
	ft_error(int num)
{
	if (num == ERRCODE0)
		write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (num == ERRCODE1)
		write(STDERR_FILENO, ERR_MSG1, ft_strlen(ERR_MSG1));
	else if (num == ERRCODE2)
		write(STDERR_FILENO, ERR_MSG2, ft_strlen(ERR_MSG2));
	else if (num == ERRCODE3)
		write(STDERR_FILENO, ERR_MSG3, ft_strlen(ERR_MSG3));
	exit(EXIT_FAILURE);
}
