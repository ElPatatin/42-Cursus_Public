/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:43:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:30:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_count_if(char **tab, int lenght, int (*f)(char *))
{
	unsigned int	cnt;
	ssize_t			i;

	cnt = 0;
	i = -1;
	while (++i < lenght)
	{
		if ((*f)(tab[i]))
			++cnt;
	}
	return (cnt);
}
