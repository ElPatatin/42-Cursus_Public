/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:35:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:44:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_save(int fd, char *buffer);
static char	*ft_get_line(char *buffer);
static char	*ft_save(char *buffer);

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
			return (NULL);
	}
	buffer[fd] = ft_read_save(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_save(buffer[fd]);
	return (line);
}

static char
	*ft_read_save(int fd, char *buffer)
{
	char	*buff;
	int		reading;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	reading = 1;
	while (!ft_strchr(buffer, '\n') && reading != 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[reading] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

static char
	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char
	*ft_save(char *buffer)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	i++;
	c = 0;
	while (buffer[i])
		str[c++] = buffer[i++];
	str[c] = '\0';
	free(buffer);
	return (str);
}
