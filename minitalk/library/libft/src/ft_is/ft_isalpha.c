/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:37:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:43:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool
	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (TRUE);
	return (FALSE);
}
