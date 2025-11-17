#include "get_next_line.h"

static char *buffer = NULL;

char * get_next_line(int fd)
{
	char *new_line;
	size_t bytes;

	bytes = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		printf("This is our buffer %s\n", buffer);
		new_line = ft_strjoin(new_line, buffer);
	}
	// idk if my bufffer(or new_line) gonna be changed in buffer managment func
	printf("%s\n", new_line);



	return(new_line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *next_line;
	next_line = get_next_line(fd);
	printf("%s", next_line);
	close(fd);
}
