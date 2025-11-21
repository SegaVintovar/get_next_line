/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:58 by vs                #+#    #+#             */
/*   Updated: 2025/11/20 13:13:51 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1, char *s2)
{
        size_t  len_s;
        size_t  i;
        size_t  p;
        char    *d;

		if (s1 == NULL)
			return (s2);
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
		// if (s1)
		// 	free(s1);
        return (d);
}

size_t  ft_strlen(const char *c)
{
	size_t	len;
	
	if (!c)
		return(0);
	len = 0;
	while (c[len] != '\0' && c)
			len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
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
			return (&r[i]);
		i++;
	}
	if (r[i] == ch)
		return (&r[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (start > ft_strlen(s))
		return ("");
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