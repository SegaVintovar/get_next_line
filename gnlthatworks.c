#include "get_next_line.h"


static char *get_the_rest(char *buffer)
{
	char	*result;
	size_t	start;
	size_t	end;
	
	start = 0;
	if (buffer && buffer[0] != '\0')
	{
		end = ft_strlen(buffer);
		if (buffer[start] != 0)
		{
			while (buffer[start] != '\n' && buffer[start] != '\0')// here is segfault
				start++;
		}
		start += 1;
		result = ft_substr(buffer, start, end - start);
		//free(buffer);
		return(result);
	}
	return (NULL);
}

static char *remove_the_rest(char *new_line)
{
	size_t i;
	size_t p;
	char *result;

	if (!new_line || *new_line == '\0')
		return (NULL);
	i = 0;
	while (new_line[i] != 0 && new_line[i] != 10)
		i++;
	result = (char *)malloc(i * sizeof(char) + 1 + 1);
	if (!result)
		return (NULL);
	p = 0;
	while(p <= i)
	{
		result[p] = new_line[p];
		p++;
	}
	result[p] = '\0';
	return (result);
}

char *reading_func(int fd)
{
	char	*tmp;
	char	*result = NULL;
	int		bytes;
	
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (bytes > 0 || bytes == BUFFER_SIZE)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		//if bytes are less than buf size then this is the end of the file
		//still some stuff to do
		if (bytes <= 0)
		{
			free(tmp);
			return (result);
		}
		tmp[bytes] = 0;
		result = ft_strjoin(result, tmp);
		if (ft_strchr(tmp, 10) != 0 )
			break;
	}
	// eof = 0;
	// if (bytes != BUFFER_SIZE)
	// 	eof = 1;
	free(tmp);
	return (result);
}

char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*tmp = NULL;
	char		*line = NULL;
	char		*gnl_hlp = NULL;
	
	if (buffer && buffer[0] != 0)
	{
		gnl_hlp = buffer;
		buffer = NULL;
	}
	if (ft_strchr(gnl_hlp, 10) == NULL)
	{
		line = reading_func(fd);
		tmp = ft_strjoin(gnl_hlp, line);
		// free(line);
		// line = NULL;
	}
	gnl_hlp = get_the_rest(tmp);
	buffer = gnl_hlp;
	line = remove_the_rest(tmp);
	if (tmp)
		free(tmp);
	if (line == NULL)
		free(buffer);
	return (line);
}

int main()
{
	int fd;
	char *str = NULL;
	
	fd = open("test.txt", O_RDONLY);
	do {
			str = get_next_line(fd);
			printf("%s", str);
			if (str)
				free(str);
	}	while (str);
	close(fd);
	return (0);
}