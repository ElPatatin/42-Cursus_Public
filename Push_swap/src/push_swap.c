/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:00:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 10:20:50 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/moves.h"

static void	ft_check_sort(t_stack *a, t_stack *b);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	ft_check_valid_params(ac, av);
	ft_init_stack_a(&a, ac, av);
	ft_init_stack_b(&b);
	ft_indexer(&a);
	ft_check_sort(&a, &b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}

static void
	ft_check_sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		ft_sa(a);
	else if (a->len == 3)
		ft_sort_three(a);
	else if (a->len == 4)
		ft_sort_four(a, b);
	else if (a->len == 5)
		ft_sort_five(a, b);
	else if (a->len <= 20)
		ft_sort_bigger(a, b, 2);
	else if (a->len <= 150)
		ft_sort_bigger(a, b, 4);
	else
		ft_sort_bigger(a, b, 8);
}

// python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`