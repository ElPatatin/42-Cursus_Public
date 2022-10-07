/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:41:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 05:58:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char
	**ft_memfree(char **ptr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}
