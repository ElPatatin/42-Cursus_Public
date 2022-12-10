/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_extra.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:00:33 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/10 20:57:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_EXTRA_H
# define PUSH_SWAP_EXTRA_H

# include "../../library/libft/inc/libft.h"
# include "../../library/ft_printf/inc/ft_printf.h"
# include "../../library/ft_gnl/inc/libgnl.h"

// Checker messages
# define VALID		(char *)"OK\n"
# define INVALID	(char *)"KO\n"

// Error Codes
# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2
# define ERRCODE3	(int)3

// Error Messages
# define ERR_MSG0	(char *)"\aError\n"
# define ERR_MSG1	(char *)"\aError! Not a valid input.\n"
# define ERR_MSG2	(char *)"\aError! Failed a node creation.\n"
# define ERR_MSG3	(char *)"\aError! Failed when making a move.\n"

typedef struct s_elems
{
	int				val;
	int				idx;
	struct s_elems	*next;
	struct s_elems	*back;
}					t_elems;

typedef struct s_stack
{
	int		len;
	t_elems	*first;
	t_elems	*last;
}			t_stack;

// Push Swap Utils
int		ft_issorted(t_elems *stack);
int		ft_check_maxint(t_ll nbr);
int		ft_while_isdigit(char *str);
void	ft_check_node(t_elems *lst, t_stack *stack);

// Check Params
void	ft_check_valid_params(int nbr, char **str);

// Stack initiation
t_elems	*ft_newnode(int nbr);
void	ft_init_stack_a(t_stack *a, int nbr, char **str);
void	ft_init_stack_b(t_stack *b);
void	ft_indexer(t_stack *stack);

// Error Functions
void	ft_error(int num);
void	ft_stack_clear(t_stack *stack);
void	ft_clean_stacks(t_stack *a, t_stack *b);
void	ft_cleanall(t_stack *a, t_stack *b, char **line);

#endif