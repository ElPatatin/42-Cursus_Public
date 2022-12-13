/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/23 18:21:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool
	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}
