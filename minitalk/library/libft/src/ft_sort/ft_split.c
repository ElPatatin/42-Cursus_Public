/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:31:16 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	**ft_mem_alloc(char const *s, char c)
{
	char	**sptr;
	int		i;
	int		j;
	int		idx;

	sptr = (char **)malloc(sizeof(char *) * (ft_str_wcount(s, c) + 1));
	if (!sptr)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_str_wcount(s, c))
	{
		idx = 0;
		while (s[j] == c)
			j++;
		while ((s[j] && s[j] != c)
			&& ((j == 0 && s[j] != c) || (s[j] != c)) && idx++ != -1)
			j++;
		sptr[i] = (char *)malloc(sizeof(char) * (idx + 1));
		if (!sptr[i])
			return (ft_memfree(sptr, i));
	}
	return (sptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		idx;

	ptr = ft_mem_alloc((char *)s, c);
	if (!ptr || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_str_wcount((char *)s, c))
	{
		idx = 0;
		while ((char)s[j] == c)
			j++;
		if ((j == 0 && (char)s[j] != c) || ((char)s[j] != c && (char)s[j]))
		{
			while ((char)s[j] && (char)s[j] != c)
				ptr[i][idx++] = (char)s[j++];
			ptr[i][idx] = '\0';
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
