/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:35:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/11/29 17:09:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char
	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_strdup("");
		if (!buffer[fd])
			return (ft_clean_line(&buffer[fd]));
	}
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (ft_clean_line(&buffer[fd]));
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_save_line(buffer[fd]);
	return (line);
}

char
	*ft_read_line(int fd, char *buffer)
{
	char	*buff;
	int		reading;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_clean_line(&buffer));
	reading = 1;
	while (!ft_strchr(buffer, '\n') && reading != 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading < 0)
		{
			ft_clean_line(&buff);
			return (ft_clean_line(&buffer));
		}
		buff[reading] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	ft_clean_line(&buff);
	return (buffer);
}

char
	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		str = (char *)malloc(sizeof(char) * i + 1);
	else
		str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		str[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char
	*ft_save_line(char *buffer)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	if (!buffer)
		return (ft_clean_line(&buffer));
	while (buffer[i] && (buffer[i] != '\n'))
		++i;
	if (buffer[i] == '\0')
		return (ft_clean_line(&buffer));
	str = ft_calloc(ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	++i;
	c = 0;
	while (buffer[i])
		str[c++] = buffer[i++];
	ft_clean_line(&buffer);
	return (str);
}

void
	*ft_clean_line(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}
