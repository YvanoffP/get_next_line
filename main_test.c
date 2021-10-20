#include "get_next_line.h"

int	main(void)
{
	char	*test;
	int		fd;

	fd = open("test.txt", O_RDONLY);

	test = get_next_line(fd);
	printf("What buffer got :...............\n%s", test);
	free(test);
	test = get_next_line(fd);
	printf("What buffer got :...............\n%s", test);
	free(test);
	test = get_next_line(fd);
	printf("What buffer got :...............\n%s", test);
	free(test);
	test = get_next_line(fd);
	printf("What buffer got :...............\n%s", test);
	free(test);
	test = get_next_line(fd);
	printf("What buffer got :...............\n%s", test);
}
