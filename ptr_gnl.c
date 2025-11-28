/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_gnl.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 12:53:13 by vs            #+#    #+#                 */
/*   Updated: 2025/11/28 11:52:27 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// allocating here
char	*reading_func(int fd, char *buffer)
{
	int bytes;
	int dif;
	char tmp[BUFFER_SIZE + 1];
	char *what_we_read;

	dif = 0;
	
	while (dif == 0 && ft_strchr(what_we_read, 10) == NULL)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes] = '\0';
		what_we_read = ft_strjoin(what_we_read, tmp);
		dif = BUFFER_SIZE - bytes;
	}
	if (dif == BUFFER_SIZE)
	{
		free(what_we_read);
		return (NULL);
	}
	return what_we_read;
}

// new line has to be reallocated and buffer allocating 
void	*extractor(char *new_line, char *buffer)
{
	char	*new_buffer = NULL;
	size_t	start;
	size_t	end;
	
	start = 0;
	end = ft_strlen(new_line);
	while (new_line && new_line[start] != 10)
	{
		start++;
	}
	buffer = ft_substr(new_line, ++start, end - start);
	new_buffer = new_line;
	free(new_line);
	new_line = NULL;
	new_line = ft_substr(new_buffer, 0, start);
	if (new_buffer)
		free(new_buffer);
}



char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *new_line;
	char *tmp = NULL;
	
	if (buffer)
	{
		new_line = ft_strjoin(tmp, buffer);
		free(buffer);
		buffer = NULL;
	}
	tmp = reading_func(fd, buffer);//allocating here
	new_line = ft_strjoin(new_line, tmp);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	extractor(new_line, buffer);
	return (new_line);
}


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
	
}

// if there is a buffer
// if there is a /n in it = extract new line. resave the buffer, return new line(free other stuff if there is some)
// if not, attach the buffer to the helper line go to the reading function
// if buffer[0] == 0 and bytes == 0
// 