/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_extra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:31:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/15 10:16:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_EXTRA_H
# define MOVES_EXTRA_H

// Instructions
# define INS_PA		(char *)"pa\n"
# define INS_PB		(char *)"pb\n"
# define INS_SA		(char *)"sa\n"
# define INS_SB		(char *)"sb\n"
# define INS_SS		(char *)"ss\n"
# define INS_RA		(char *)"ra\n"
# define INS_RB		(char *)"rb\n"
# define INS_RR		(char *)"rr\n"
# define INS_RRA	(char *)"rra\n"
# define INS_RRB	(char *)"rrb\n"
# define INS_RRR	(char *)"rrr\n"

// Push Moves
int	ft_pa(t_stack *a, t_stack *b);
int	ft_pb(t_stack *a, t_stack *b);

// Swap moves
int	ft_sa(t_stack *a);
int	ft_sb(t_stack *b);
int	ft_ss(t_stack *a, t_stack *b);

// Rotate moves
int	ft_ra(t_stack *a);
int	ft_rb(t_stack *b);
int	ft_rr(t_stack *a, t_stack *b);

// Reverese rotate moves
int	ft_rra(t_stack *a);
int	ft_rrb(t_stack *b);
int	ft_rrr(t_stack *a, t_stack *b);

#endif
