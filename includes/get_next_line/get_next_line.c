/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:06:08 by ktwomey           #+#    #+#             */
/*   Updated: 2018/07/01 14:12:09 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char			*ft_line(char **line, char **line_read, int fd)
{
	char		*temp;
	int			n;

	n = 0;
	while (line_read[fd][n] != '\n' && line_read[fd][n] != '\0')
		n++;
	if (line_read[fd][n] == '\n')
	{
		*line = ft_strsub(line_read[fd], 0, n);
		temp = ft_strdup(&line_read[fd][n + 1]);
		free(line_read[fd]);
		line_read[fd] = temp;
		if (line_read[fd][0] == '\0')
			ft_strdel(&line_read[fd]);
	}
	else if (line_read[fd][n] == '\0')
	{
		*line = ft_strdup(line_read[fd]);
		ft_strdel(&line_read[fd]);
	}
	return (*line);
}

int					get_next_line(const int fd, char **line)
{
	static char	*line_read[0];
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	if (!line || fd < 0)
		return (-1);
	if (line_read[fd] == NULL)
		line_read[fd] = ft_strnew(0);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		temp = ft_strjoin(line_read[fd], buff);
		free(line_read[fd]);
		line_read[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	if (i == 0 && (line_read[fd] == NULL || line_read[fd][0] == '\0'))
		return (0);
	*line = ft_line(line, line_read, fd);
	return (1);
}
