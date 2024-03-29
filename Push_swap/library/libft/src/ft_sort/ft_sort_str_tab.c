/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:33 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:31:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_sort_str_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i;
		while (j > 0 && ft_strcmp(tab[j - 1], tab[j]) > 0)
		{
			tmp = tab[j - 1];
			tab[j - 1] = tab[j];
			tab[j] = tmp;
			j--;
		}
		i++;
	}
}
