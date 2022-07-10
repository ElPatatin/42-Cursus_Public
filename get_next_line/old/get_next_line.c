/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:35:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/06/11 12:24:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_buffln(char *buff, int size)
{
	unsigned int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i + 1);
		else if (buff[i] == '\0')
			return (-2);
		++i;
	}
	if (size == 0)
		return (i);
	return (-1);
}

char	*ft_linealloc(int fd, char *tmpbuff, char *buffer)
{
	int	i;

	i = 0;
	while (ft_buffln(tmpbuff, BUFFER_SIZE) == -1 && fd)
	{
		read(fd, tmpbuff, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, ft_strdup(tmpbuff));
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*buffer;
	char		*tmpbuff;
	ssize_t		idx;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmpbuff = ft_calloc(BUFFER_SIZE);
	buffer = ft_calloc(BUFFER_SIZE);
	buffer = ft_linealloc(fd, tmpbuff, buffer);
	idx = ft_buffln(buffer, BUFFER_SIZE) + 1;
	buff = (char *)malloc(sizeof(char) * idx);
	if (!buff)
		return (NULL);
	buff = ft_strlcpy(buff, buffer, idx);
	buff[idx] = '\0';
	return (buff);
}
