#include "get_next_line.h"

int	main(void)
{
	char	*test;
	int		fd;

	fd = 1;

	test = get_next_line(open("test.txt", O_RDONLY));
	printf("Buffer size : %i\n", BUFFER_SIZE);
	printf("What buffer got : %s\n", test);
}
