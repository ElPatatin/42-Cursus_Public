/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:57:12 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/17 15:25:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Esta función permite encontrar la primera ocurrencia de la string set dentro
// de la string a cortar y devuelve el valor de ese momento.

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

// Esta función permite encontrar la última ocurrencia de la string set dentro
// de la string a cortar y devuelve el valor de ese demomento.

static int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = ft_getstart(s1, set);
	j = ft_getend(s1, set);
	if (i >= j)
		return (ft_strdup(""));
	dst = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1 + i, j - i + 1);
	return (dst);
}

/*										*/
/*	La función strtrim cortará una string por el principio y por el final	*/
/*	si encuentra una ocurrencia de la string set pasada como parámetro.	*/
/*										*/
