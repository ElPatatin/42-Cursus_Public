/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_sort_str_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:42:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:49:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_adv_sort_str_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i;
		while (j > 0 && (*cmp)(tab[j - 1], tab[j]) > 0)
		{
			tmp = tab[j - 1];
			tab[j - 1] = tab[j];
			tab[j] = tmp;
			j--;
		}
		i++;
	}
}
