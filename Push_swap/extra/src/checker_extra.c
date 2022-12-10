/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/10 20:57:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_extra.h"
#include "../inc/moves_extra.h"

static void	ft_read_commands(t_stack *a, t_stack *b);
static int	ft_check_moves(char *line, t_stack *a, t_stack *b);

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
	ft_read_commands(&a, &b);
	if (b.len == 0)
	{
		if (!ft_issorted(a.first))
			ft_printf("%s", INVALID);
		else
			ft_printf("%s", VALID);
	}
	else
		ft_printf("%s", INVALID);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

static void
	ft_read_commands(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
		if (!ft_check_moves(line, a, b))
			ft_cleanall(a, b, &line);
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	free(line);
	line = NULL;
}

static int
	ft_check_moves(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, INS_PA))
		return (ft_pa(a, b));
	else if (!ft_strcmp(line, INS_PB))
		return (ft_pb(a, b));
	else if (!ft_strcmp(line, INS_SA))
		return (ft_sa(a));
	else if (!ft_strcmp(line, INS_SB))
		return (ft_sb(b));
	else if (!ft_strcmp(line, INS_SS))
		return (ft_ss(a, b));
	else if (!ft_strcmp(line, INS_RA))
		return (ft_ra(a));
	else if (!ft_strcmp(line, INS_RB))
		return (ft_rb(b));
	else if (!ft_strcmp(line, INS_RR))
		return (ft_rr(a, b));
	else if (!ft_strcmp(line, INS_RRA))
		return (ft_rra(a));
	else if (!ft_strcmp(line, INS_RRB))
		return (ft_rrb(b));
	else if (!ft_strcmp(line, INS_RRR))
		return (ft_rrr(a, b));
	else
		ft_cleanall(a, b, &line);
	return (0);
}
