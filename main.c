#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("txt.txt2", O_RDONLY);
	if (!fd)
		return 0;
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
