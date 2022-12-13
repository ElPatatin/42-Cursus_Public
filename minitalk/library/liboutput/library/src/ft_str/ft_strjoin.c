/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:41:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/19 23:15:01 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;
	size_t	newlen;

	newlen = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}	
	new = (char *)malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}
