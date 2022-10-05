/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:18:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/05 18:51:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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
	ft_cleanall(t_stack *a, t_stack *b, char **line)
{
	free(*line);
	line = NULL;
	ft_stackclear(a);
	ft_stackclear(b);
	ft_error(ERRCODE0);
}

void
	ft_error(int num)
{
	if (num == ERRCODE0)
		ft_printf("%s", ERR_MSG0);
	else if (num == ERRCODE1)
		ft_printf("%s", ERR_MSG1);
	else if (num == ERRCODE2)
		ft_printf("%s", ERR_MSG2);
	else if (num == ERRCODE3)
		ft_printf("%s", ERR_MSG3);
	exit(EXIT_FAILURE);
}
