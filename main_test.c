#include "get_next_line.h"

int	main(void)
{
	char	*test;
	int		fd;

	fd = open("gnlTester/files/41_with_nl", O_RDONLY);

	printf("What we got :\n");
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	printf("What we got :\n");
	test = get_next_line(fd);
	printf("%s", test);
	printf("What we got :\n");
	test = get_next_line(fd);
	printf("%s", test);
}
