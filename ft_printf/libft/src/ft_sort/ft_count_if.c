/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:43:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/07/18 17:43:54 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lib_ft.h"

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
