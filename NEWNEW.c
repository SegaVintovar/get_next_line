/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NEWNEW.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:04:49 by vsudak            #+#    #+#             */
/*   Updated: 2025/11/22 11:42:45 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *remove_the_rest(char *new_line)
{
	size_t i;
	size_t p;
	char *result;

	if (*new_line == '\0')
		return (NULL);
	i = 0;
	while (new_line[i] != 10)
		i++;
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
	// if (*new_line)
	// 	free(new_line);
	return (result);
}

static char *get_the_rest(char *buffer)
{
	char	*result;
	size_t	start;
	size_t	end;
	
	start = 0;
	if (buffer != NULL || buffer[0] != '\0')
	{
		//result = *ft_strchr(buffer, 10) + 1;
		end = ft_strlen(buffer);
		while (buffer[start] != '\n')
				start++;
		start += 1;
		result = ft_substr(buffer, start, end - start);
		// if (buffer != NULL)
		// 	free(buffer);
		return(result);
	}
	return (NULL);
}

char *buf_is(char *buffer)
{
	char *line;

	line = buffer;
	if (ft_strchr(line, 10) != 0)// then checing if there is a \n
	{
		buffer = get_the_rest(buffer);
		// if the buffer is empty - free it
		line = remove_the_rest(line);
		//free before return. how to free correctly?
		return (line);
	}
	
}

//check up for mallocs
char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char		*tmp;
	int			bytes = 1;
	char 		*line = NULL;
	
	if (buffer != NULL)//what do we do when there is something in the buffer?
		line = buf_is(buffer);//yes, we are attaching it to the line
	while (bytes > 0)
	{
		tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		bytes = read(fd, tmp, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(tmp, 10) != 0)
			break;
		if (bytes < 0)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
	}
	free(tmp);
	if (bytes <= 0)//EOF or wrong fd
		//free(buffer);
		// free(line);
		return (NULL);
	line = buffer;
	//if (line != NULL)
	line = remove_the_rest(line);
	if (*buffer != 0)
		buffer = get_the_rest(buffer);
	// if (*buffer == 0)
	// 	free(buffer);
	return (line);
}

int	main()
{
	int fd;
	char *str = NULL;
	int lines_print = 15;
	int i = 0;
	
	fd = open("test.txt", O_RDONLY);
	while (i < lines_print)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	close(fd);
	return (0);
}
