/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:38:28 by kyukang           #+#    #+#             */
/*   Updated: 2024/06/06 14:39:04 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_readfile(int fd, char *string, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!string)
			string = ft_strdup("");
		tmp = string;
		string = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (string);
}

static char	*ft_freeline(char *string)
{
	char	*remainder;
	int		i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\0' || string[1] == '\0')
		return (NULL);
	remainder = ft_substr(string, i + 1, ft_strlen(string) - i);
	if (*remainder == 0)
	{
		free(remainder);
		remainder = NULL;
	}
	string[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder[MAX_FD];

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_readfile(fd, remainder[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder[fd] = ft_freeline(line);
	return (line);
}
