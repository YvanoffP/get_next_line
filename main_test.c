#include "get_next_line.h"

int	main(void)
{
	char	*test;
	int		fd;

	fd = 1;

	test = get_next_line(open("test.txt", O_RDONLY));
	printf("What buffer got :...............\n%s", test);
	free(test);
	test = get_next_line(open("test.txt", O_RDONLY));
	printf("What buffer got :...............\n%s", test);
}
