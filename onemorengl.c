/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onemorengl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 12:58:35 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/24 16:02:41 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *get_the_rest(char *buffer)
{
	char	*result;
	size_t	start;
	size_t	end;
	
	start = 0;
	if (buffer && buffer[0] != '\0')
	{
		//result = *ft_strchr(buffer, 10) + 1;
		end = ft_strlen(buffer);
		if (buffer[start] != 0)
		{
			while (buffer[start] != '\n')
			start++;
		}
		start += 1;
		result = ft_substr(buffer, start, end - start);
		// if (buffer)
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

	if (!new_line || *new_line == '\0')
		return (NULL);
	i = 0;
	while (new_line[i] != 10)
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
	// if (new_line)
	// 	free(new_line);
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
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = 0;
		result = ft_strjoin(result, tmp);//here is allocation
		if (ft_strchr(tmp, 10) != 0)
			break;
	}
	free(tmp);
	return (result);
}

// char	*buf_is(buffer)
// {
	
// }

char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*tmp = NULL;
	char		*line = NULL;
	char		*gnl_hlp = NULL;
	
	if (buffer)
	{
		//tmp = ft_strjoin(tmp, buffer);//realloc tmp, and copy buffer there
		gnl_hlp = buffer;
		//free(buffer);
		buffer = NULL;
	}
	if (ft_strchr(tmp, 10) == NULL)
	{
		line = reading_func(fd);
		tmp = ft_strjoin(gnl_hlp, line);
		free(line);
		// line = NULL;
	}
	gnl_hlp = get_the_rest(tmp);
	buffer = gnl_hlp;
	if (gnl_hlp)
		free(gnl_hlp);
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
	
	// while (str = get_next_line) {
		
	// }
	
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
	str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// if (str)
	// 	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// if (str)
	// 	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	close(fd);

	return (0);
}