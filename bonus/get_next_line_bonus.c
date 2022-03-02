/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:39:50 by binam             #+#    #+#             */
/*   Updated: 2022/02/02 14:49:35 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(int fd, char *buffer)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_nl_char(buffer) && rd_byte != 0)
	{
		rd_byte = read (fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		buffer = strjoin(buffer, buff);
	}
	free (buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s_buffer[1025];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1025)
		return (0);
	s_buffer[fd] = get_line(fd, s_buffer[fd]);
	if (s_buffer[fd] == NULL)
		return (NULL);
	line = get_new_line(s_buffer[fd]);
	s_buffer[fd] = get_new_buffer(s_buffer[fd]);
	return (line);
}
/*
int	main()
{
	int fd = open("deneme.txt",O_RDONLY);
	int fd2 = open ("denm.txt",O_RDONLY);
	int kontrol = 1;
	char *kelime;
	while (kontrol)
	{
		kelime = get_next_line(fd);
		if(!kelime)
			kontrol = 0;
		printf("%s",kelime);
	}
	kelime = 0;
	kontrol = 1;
	while (kontrol)
	{		kelime = get_next_line(fd2);
		if(!kelime)
			kontrol = 0;
		printf("%s",kelime);
	}
	printf("%d",fd);
}*/
