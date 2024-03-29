/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:58:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:39:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull
	ft_stoul(t_ull nbr)
{
	t_ull	unbr;

	unbr = nbr + ULONG_MAX + 1;
	return (unbr);
}
