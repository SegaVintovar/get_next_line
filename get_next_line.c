/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 12:53:13 by vs            #+#    #+#                 */
/*   Updated: 2025/11/29 18:47:40 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// allocating here, there \n in return or \0
// char	*reading_func(int fd)
// {
// 	int		bytes;
// 	char	tmp[BUFFER_SIZE + 1];
// 	char	*what_we_read;

// 	what_we_read = NULL;
// 	bytes = 1;
// 	while (bytes > 0 && ft_strchr(what_we_read, 10) == NULL)
// 	{
// 		bytes = read(fd, tmp, BUFFER_SIZE);
// 		if (bytes < 0)
// 		{
// 			free(what_we_read);
// 			return (free(what_we_read), NULL);
// 		}
// 		tmp[bytes] = '\0';
// 		what_we_read = ft_strjoin(what_we_read, tmp);
// 	}
// 	if (bytes < 0)
// 		return (free(what_we_read), NULL);
// 	return (what_we_read);
// }

char	*reading_func(int fd)
{
	int		bytes;
	char	*tmp;
	char	*what_we_read;

	what_we_read = NULL;
	bytes = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(tmp), NULL);
	while (bytes > 0 && ft_strchr(what_we_read, 10) == NULL)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (free(tmp), free(what_we_read), NULL);
		tmp[bytes] = '\0';
		what_we_read = ft_strjoin(what_we_read, tmp);
	}
	if (bytes < 0)
		return (free(tmp), free(what_we_read), NULL);
	return (free(tmp), what_we_read);
}

char	*line_extractor(char *line)
{
	char	*new_line;
	size_t	start;

	new_line = NULL;
	start = 0;
	if (!line)
		return (NULL);
	while (line && (line[start] != 10 && line[start] != 0))
		start++;
	new_line = ft_substr(line, 0, start + 1);
	return (new_line);
}

char	*buffer_extractor(char *line)
{
	char	*buffer;
	size_t	start;
	size_t	end;
	char	*empty;

	buffer = NULL;
	empty = "";
	if (!line)
		return (NULL);
	end = ft_strlen(line);
	start = 0;
	while (line && (line[start] != 10 && line[start] != 0))
		start++;
	start += 1;
	if (start == end)
		return (free(line), NULL);
	buffer = ft_substr(line, start, end - start);
	if (buffer == empty)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	free(line);
	return (buffer);
}

// linux stack size 8mb. then we need safe_margin, a room for other stuff
// to check the stack size we can use a command: ulimit -s
// 
char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*new_line;
	char		*what_we_read;
	char		*workspace;

	new_line = NULL;
	what_we_read = NULL;
	workspace = NULL;
	if (buffer && ft_strchr(buffer, 10) != NULL)
	{
		new_line = line_extractor(buffer);
		buffer = buffer_extractor(buffer);
		return (new_line);
	}
	what_we_read = reading_func(fd);
	if (what_we_read == NULL && (!buffer || buffer[0] == 0))
		return (free(what_we_read), free(buffer), NULL);
	workspace = ft_strjoin(buffer, what_we_read);
	if (what_we_read == NULL && buffer == NULL)
		return (free(what_we_read), NULL);
	new_line = line_extractor(workspace);
	buffer = buffer_extractor(workspace);
	return (free(what_we_read), new_line);
}

// char *get_next_line(int fd)
// {
// 	static char *buffer = NULL;
// 	char *new_line;
// 	char *tmp = NULL;
// 	if (buffer)
// 	{
// 		new_line = ft_strjoin(tmp, buffer);
// 		free(buffer);
// 		buffer = NULL;
// 	}
// 	tmp = reading_func(fd);//allocating here
// 	new_line = ft_strjoin(new_line, tmp);
// 	if (tmp)
// 	{
// 		free(tmp);
// 		tmp = NULL;
// 	}
// 	new_line = line_extractor(new_line);
// 	return (new_line);
// }
// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str;
// 	int eof = 0;
// 	// do {
// 	// 	str = get_next_line(fd);
// 	// 	if (str)
// 	// 	{
// 	// 		printf("%s", str);
// 	// 		free(str);
// 	// 	}
// 	// }	while (str);
// 	str = reading_func(fd, eof);
// 	if (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	printf("\n%i\n", eof);
// 	close(fd);
// }
// if there is a buffer
// if there is a /n in it = extract new line. resave the buffer, 
// return new line(free other stuff if there is some)
// if not, attach the buffer to the helper line go to the reading function
// if buffer[0] == 0 and bytes == 0
// 