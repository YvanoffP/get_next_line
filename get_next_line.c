/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:53:21 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/21 21:35:55 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline_index(char *str)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

static char	*extract(char **save, int len)
{
	char	*swp;
	char	*ret;

	if (!*save)
		return (NULL);
	ret = ft_substr(*save, 0, len + 1);
	swp = ft_strdup(*save + len + 1);
	free(*save);
	*save = swp;
	return (ret);
}

static void	append(char **save, char *read_buffer)
{
	char	*swp;

	if (!read_buffer)
		return ;
	swp = ft_strjoin(*save, read_buffer);
	free(*save);
	*save = swp;
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	int			read_count;
	int			index;

	index = -1;
	
	if (!fd)
		return (NULL);

	while (1)
	{
		index = newline_index(save);
		if (index > -1)
			break ;

		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count == 0)
			break ;

		read_buffer[read_count] = '\0';

		if (!save)
			save = ft_strdup(read_buffer);
		else
			append(&save, read_buffer);
	}
	if (index > -1)
		return (extract(&save, index));
	if (!save)
		return (NULL);
	return (extract(&save, ft_strlen(save)));
}
