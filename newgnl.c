#include "get_next_line.h"

static char *buffer = NULL;

static char *get_the_rest(char *buffer)
{
	char *result;
	
	if (buffer != NULL || buffer[0] != '\0')
	{
		result = ft_strchr(buffer, 10) + 1;
		// if (buffer != NULL)
		// 	free(buffer);
		return(result);
	}
	return (NULL);
}

static char *remove_the_rest(char *new_line)
{
	size_t i;
	size_t p;
	char *result;

	i = 0;
	while (new_line[i] != 10)
	{
		i++;
	}
	result = (char *)malloc(i * sizeof(char) + 1);
	if (!result)
		return (NULL);
	p = 0;
	while(p <= i)
	{
		result[p] = new_line[p];
		p++;
	}
	result[p] = '\0';
	// printf("%s", new_line);
	// if (new_line)
	// 	free(new_line);
	return (result);
}

char	*get_next_line(int fd)
{
	char	*new_line = 0;
	size_t	bytes;

	if (buffer != NULL)
	{
		if (ft_strchr(buffer, 10))
		{
			new_line = remove_the_rest(buffer);
			buffer = get_the_rest(buffer);
			return (new_line);
		}
		new_line = ft_strjoin(new_line, buffer);
	}
	bytes = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			if (*new_line == '\0')
				return (NULL);
			else
				return (new_line);
		buffer[bytes] = '\0';
		new_line = ft_strjoin(new_line, buffer);
	}
	if (buffer == NULL)
		return (NULL);
	buffer = get_the_rest(buffer);
	new_line = remove_the_rest(new_line);
	return(new_line);
}

// char *read_file_till_the_end(int fd)
// {
// 	while ()
// }

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *next_line;
	next_line = get_next_line(fd);
	printf("%s", next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	free(next_line);
	close(fd);
}
