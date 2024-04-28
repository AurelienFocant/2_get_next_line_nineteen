#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	int	*ptr;

	ptr = malloc(8);

	fd = open("txt.txt", O_RDONLY);
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
