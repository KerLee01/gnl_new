 #include "get_next_line.h"

 int main(void)
 {
 	int fd = open("text.txt", O_RDONLY);
 	char *line;

 	line = get_next_line(fd);
 	while(line != NULL)
 	{
 		printf("line: %s\n", line);
 		free(line);
 		line = get_next_line(fd);
 	}

 	return 0;
 }
