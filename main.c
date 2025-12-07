// #include "get_next_line.h"
//
// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line;
//
// 	line = get_next_line(fd);
// 	while(line != NULL)
// 	{
// 		printf("line: %s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
//
// 	return 0;
// }

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("huge_line.txt", O_RDONLY);
	while(1)
	{
		char *line = get_next_line(fd);
		printf("%s\n", line);
		if(line == NULL)
			break;
	}
	char *line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	return 0;
}
