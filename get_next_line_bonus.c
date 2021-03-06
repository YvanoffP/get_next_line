/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:50:35 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 14:51:15 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*extract(char **save, int read_count)
{
	char	*swp;
	char	*ret;
	int		size;

	if (!**save)
		free(*save);
	if (!**save)
		return (NULL);
	size = newline_index(*save) + 1;
	if (size == 0)
		size = ft_strlen(*save);
	ret = ft_substr(*save, 0, size);
	swp = ft_substr(*save, size, ft_strlen(*save) - size);
	free(*save);
	if (read_count == 0)
	{
		free(swp);
		*save = NULL;
		return (ret);
	}
	*save = swp;
	return (ret);
}

static void	append(char **save, char *read_buffer, int read_count)
{
	char	*swp;

	if (!read_buffer)
		return ;
	read_buffer[read_count] = 0;
	swp = ft_strjoin(*save, read_buffer);
	free(*save);
	*save = swp;
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		read_buffer[BUFFER_SIZE + 1];
	int			read_count;
	int			index;

	index = -1;
	if (read(fd, 0, 0))
		return (NULL);
	while (1)
	{
		index = newline_index(save[fd]);
		if (index > -1)
			break ;
		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count == 0)
			break ;
		if (!save[fd])
			save[fd] = ft_substr(read_buffer, 0, read_count);
		else
			append(&save[fd], read_buffer, read_count);
	}
	if (!save[fd])
		return (NULL);
	return (extract(&save[fd], read_count));
}
