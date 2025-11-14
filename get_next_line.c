/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/10 10:42:47 by vs            #+#    #+#                 */
/*   Updated: 2025/11/14 14:37:45 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len] != '\0')
		len ++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s;
	size_t	i;
	size_t	p;
	char	*d;
	
	i = ft_strlen(s1) + 1;
	len_s = i + ft_strlen(s2);
	d = malloc(len_s);
	i = 0;
	while (s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	p = 0;
	while (i < len_s)
		d[i++] = s2[p++];
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			d[i] = s[i];
			i++;
		}
	}
	d[i] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}



/// @brief splits the buf with \n, appends \n and stuff before \n to new line
/// @param buf stuff we read and where we found \n
/// @param new_line the line that GNL returns
/// @param i position of the \n
/// @return ???
char *split_the_buf_to_store_in_static(char *buf, size_t i)
{
	return (ft_substr(buf, i, BUFFER_SIZE - i + 1));
}

char *extra(char *buf, size_t i)
{
	return (ft_substr(buf, 0, i + 1));
}

int	ft_strchr(char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	ch;

	if (s == NULL)
		return (0);
	ch = (unsigned char)c;
	r = (char *)s;
	i = 0;
	while (r[i] != '\0')
	{
		if (r[i] == ch)
			return (i);
		i++;
	}
	//if (r[i] == ch)
	//	return (i);
	return (0);
}


//char *leftover_stuff(char *buff)
// {
// 	// we are passing here a buff and checking if there is a \n 
// 	// if it is there we are returning 1
// 	size_t	i;

// 	i = 0;
// }

//	_ _ _ _ _   _ _ _ \n_ _

char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*buf;
	size_t		i;
	int			trigger;
	char		*new_line;
	//char		*extra;
	
	trigger = 1;
	i = 0;
	new_line = "";
	if (buffer != NULL)
		ft_strjoin(new_line, buffer);
	while (trigger > 0) // there is what to save, we are saving to the buffer)
	{
		//buf = NULL;// do I need this???
		buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		trigger = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (ft_strchr(buf, 10) != 0)
		{
			i = ft_strchr(buf, 10);
			;
			buffer = split_the_buf_to_store_in_static(buf, i);
			new_line = ft_strjoin(new_line, extra(buf, i));
			break;
		}
		new_line = ft_strjoin(new_line, buf);
		i++;
	}
	return (new_line);
}

int main()
{
//	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("test.txt", O_RDONLY);
	char *str;
	
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	free(str);
	close(fd1);
}