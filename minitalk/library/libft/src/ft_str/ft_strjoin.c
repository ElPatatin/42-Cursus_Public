/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/02/08 17:56:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;
	size_t	newlen;

	newlen = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}	
	new = (char *)ft_calloc((newlen + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i + j] = s2[j];
	free(s1);
	s1 = NULL;
	return (new);
}
