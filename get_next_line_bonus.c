/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 12:08:54 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/30 13:21:47 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[1024];
	char		*new_line;
	char		*what_we_read;
	char		*workspace;

	new_line = NULL;
	what_we_read = NULL;
	workspace = NULL;
	if (fd < 0 || fd > 1024)
		return (NULL);
	if (buffer[fd] && ft_strchr(buffer[fd], 10) != NULL)
	{
		new_line = line_extractor(buffer[fd]);
		buffer[fd] = buffer_extractor(buffer[fd]);
		return (new_line);
	}
	what_we_read = reading_func(fd);
	workspace = ft_strjoin(buffer[fd], what_we_read);
	if (what_we_read == NULL && buffer[fd] == NULL)
		return (free(workspace), free(what_we_read), NULL);
	new_line = line_extractor(workspace);
	buffer[fd] = buffer_extractor(workspace);
	return (free(what_we_read), new_line);
}
