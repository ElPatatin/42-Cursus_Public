/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:02 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:50:16 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int		i;
	int		plus;
	int		minus;

	i = -1;
	plus = 0;
	minus = 0;
	while (++i < (lenght - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			minus++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			plus++;
	}
	return (plus == i || minus == i);
}
