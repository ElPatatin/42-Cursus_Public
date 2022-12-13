/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:52:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:03:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start(const char *s1, const char *set);
static int	ft_get_end(const char *s1, const char *set);

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = ft_get_start(s1, set);
	j = ft_get_end(s1, set);
	if (i >= j)
		return (ft_strdup(""));
	dst = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1 + i, j - i + 1);
	return (dst);
}

static int
	ft_get_start(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr((char *)set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int
	ft_get_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr((char *)set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}
