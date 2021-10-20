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

static int	have_newline(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
	{
		count++;
	}
	if (str[count] == '\n')
		return (count);
	else
		return (0);
}

static int	have_multnewline(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			count++;
		index++;
	}
	return (count);
}

static char	*sender(char **save, int len)
{
	char	*tmp;
	char	*ret;

	ret = ft_substr(*save, 0, len + 1);
	tmp = ft_strdup(&((*save)[len + 1]));
	free(*save);
	*save = tmp;
	return (ret);
}

static void	saver(char **save, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buff);
	free(*save);
	*save = tmp;
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	char		*ret;
	int			nbread;

	ret = NULL;
	nbread = 1;
	while (nbread > 0 && !ret)
	{
		nbread = read(fd, buff, BUFFER_SIZE);
		buff[nbread] = '\0';
		if (!save)
			save = ft_strdup(buff);
		else
			saver(&save, buff);
		if (have_newline(save))
			return (sender(&save, have_newline(save)));
	}
	if (have_multnewline(save) > 1)
		return (sender(&save, have_newline(save)));
	if (nbread == 0)
		return (save);
	else
		return (ret);
}
