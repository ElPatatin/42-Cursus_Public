/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:12:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/06 16:36:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	ft_check_isdigit(int nbr, char **str);
static int	ft_check_dups(int nbr, char **str);
// static int	ft_check_order(int nbr, char **str);

void
	ft_check_valid_params(int nbr, char **str)
{
	if (!ft_check_isdigit(nbr, str))
		ft_error(ERRCODE0);
	if (!ft_check_dups(nbr, str))
		ft_error(ERRCODE0);
}

static int
	ft_check_isdigit(int nbr, char **str)
{
	ssize_t	idx;
	t_ll	tmpnbr;

	idx = 0;
	while (++idx < nbr)
	{
		if (!ft_while_isdigit(str[idx]))
			return (0);
		tmpnbr = ft_atoi(str[idx]);
		if (!ft_check_maxint(tmpnbr))
			return (0);
	}
	return (1);
}

static int
	ft_check_dups(int nbr, char **str)
{
	ssize_t	idx;
	ssize_t	jdx;
	t_ll	nbr1;
	t_ll	nbr2;

	idx = 0;
	while (++idx < nbr)
	{
		jdx = idx;
		nbr1 = ft_atoi(str[idx]);
		while (++jdx < nbr)
		{
			nbr2 = ft_atoi(str[jdx]);
			if (nbr1 == nbr2)
				return (0);
		}
	}
	return (1);
}
