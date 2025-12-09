#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int i = 0;

	fd = open("giant_line.txt", O_RDONLY);
	line = get_next_line(fd);
	while(i < 100)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);

	return 0;
}
