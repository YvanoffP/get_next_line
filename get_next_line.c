/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:53:21 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/16 22:01:15 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	set_strlen(char *str, char set)
{
	size_t	count;

	count = 0;
	while (str[count] != set)
		count++;
	return (count);
}

static char	*copy_line(char *str)
{
	char	*newline;
	size_t	index;
	size_t	len;

	len = set_strlen(str, '\n');
	index = 0;
	newline = malloc(sizeof(char) * (len + 1));
	if (!newline)
		return (NULL);
	while (index <= len)
	{
		newline[index] = str[index];
		index++;
	}
	newline[index] = '\0';
	return (newline);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		nbread;
	char	*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbread = read(fd, buffer, BUFFER_SIZE);
	line = copy_line(buffer);
	return (line);
}
