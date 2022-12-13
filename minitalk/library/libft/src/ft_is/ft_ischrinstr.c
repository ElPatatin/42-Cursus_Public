/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischrinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:36:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:22:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool
	ft_ischrinstr(char *str)
{
	while (*str)
	{
		if (ft_strchr(&str[1], str[0]))
			return (TRUE);
		str++;
	}
	return (FALSE);
}
