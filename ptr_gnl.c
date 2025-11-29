/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:53:13 by vs                #+#    #+#             */
/*   Updated: 2025/11/29 13:09:37 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// allocating here, there \n in return or \0
char	*reading_func(int fd)
{
	int bytes;
	int dif;
	char tmp[BUFFER_SIZE + 1];
	char *what_we_read = NULL;

	dif = 0;
	bytes = 1;
	while (bytes > 0 && ft_strchr(what_we_read, 10) == NULL)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <=0 )
			break;
		tmp[bytes] = '\0';
		what_we_read = ft_strjoin(what_we_read, tmp);
		dif = BUFFER_SIZE - bytes;
	}
	if (dif == BUFFER_SIZE)
	{
		free(what_we_read);
		return (NULL);
	}
	return (what_we_read);
}


char	*line_extractor(char *line)
{
	char *new_line = NULL;
	size_t	start;
	
	start = 0;
	// if (line[0] == 0)
	// {
	// 	free(line);
	// 	return (NULL);
	// }
	if (!line)
		return (NULL);
	while (line && (line[start] != 10 && line[start] != 0))
		start++;
	new_line = ft_substr(line, 0, start + 1);
	return(new_line);
}

char	*buffer_extractor(char *line)
{
	char	*buffer = NULL;
	size_t	start;
	size_t	end;
	char	*empty;
	
	empty = "";
	if (!line)
		return (NULL);
	end = ft_strlen(line);
	start = 0;
	// if (line[0] == 0)
	// {
	// 	free(line);
	// 	return (NULL);
	// }
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


char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*new_line = NULL;
	char		*what_we_read = NULL;
	char		*workspace = NULL;
	
	if (buffer && ft_strchr(buffer, 10) != NULL)
	{
		new_line = line_extractor(buffer);
		buffer = buffer_extractor(buffer);// here is free
		return (new_line);
	}
	what_we_read = reading_func(fd);// allocating here
	if (what_we_read == NULL && (!buffer || buffer[0] == 0))
		return (free(what_we_read), free(buffer), NULL);
	workspace = ft_strjoin(buffer, what_we_read);
	if (what_we_read == NULL && buffer == NULL)// reallcation of the tmp
		return (free(what_we_read), NULL);
	new_line = line_extractor(workspace);
	buffer = buffer_extractor(workspace);// here is free
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


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	// do {
	// 	str = get_next_line(fd);
		
	// 	if (str)
	// 	{
	// 		printf("%s", str);
	// 		free(str);
	// 	}
	// }	while (str);

	str = reading_func(fd);
	
	if (str)
	{
		printf("%s", str);
		free(str);
	}
}

// if there is a buffer
// if there is a /n in it = extract new line. resave the buffer, return new line(free other stuff if there is some)
// if not, attach the buffer to the helper line go to the reading function
// if buffer[0] == 0 and bytes == 0
// 