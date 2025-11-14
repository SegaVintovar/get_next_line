/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:42:47 by vs                #+#    #+#             */
/*   Updated: 2025/11/13 22:55:53 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
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
		d[i++] = s1[i];
	p = 0;
	while (i < len_s)
		d[i++] = s2[p++];
	d[i] = '\0';
	return (d);
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
	if (r[i] == ch)
		return (i);
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
	
	trigger = 1;
	i = 0;
	new_line = "";
	while (trigger > 0) // there is what to save, we are saving to the buffer)
	{
		buf = NULL;
		buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		trigger = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (ft_strchr(buf, 10) == 0)
			break;
		new_line = ft_strjoin(new_line, buf);
		
		i++;
	}
	printf("%s\n", new_line);
	printf("we read %lu amount of times\n", i);

	// split the buf
	
//	buffer = leftover chars from buf;
	
	// check buff for the \n (new_line)
//	printf("%s/n", new_line);
	// save leftover data after the \n
	
	// malloc the string to save it
	
	// as soon as there is an end of the file or \n
	// we are printing
	return (new_line);
}

int main()
{
//	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("1test.txt", O_RDONLY);
	char *str;
	
	str = get_next_line(fd1);
	printf("%s\n", str);
	//free(str);
	close(fd1);
}