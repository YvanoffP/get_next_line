/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:39:06 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/21 23:57:34 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*test;
	int		fd;

	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
	printf("What we got :");
	test = get_next_line(fd);
	printf("%s", test);
}
