/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 10:45:58 by vs            #+#    #+#                 */
/*   Updated: 2025/11/23 17:19:18 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	
	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);

	result = join_help(s1, s2, len1, len2);
	if (s1)
		free(s1);
	return (result);
}

char *join_help(char *s1, const char *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	p;
	char	*result;

	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = p = 0;
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[p] != '\0')
	{
		result[i + p] = s2[p];
		p++;
	}
	result[i + p] = 0;
	return (result);
}

// char	*ft_strjoin(char *s1, const char *s2)
// {
// 		size_t	len_s;
// 		size_t	i;
// 		char	*d;
// 		size_t	k;

// 		if (s1 == NULL)
// 			i = 1;
// 		else
// 			i = ft_strlen(s1) + 1;
// 		if (s2 == NULL)
// 			len_s = i;
// 		else
// 			len_s = i + ft_strlen(s2);
// 		d = malloc(len_s);
// 		if (!d)
// 		{
// 			free(s1);
// 			return (NULL);
// 		}
// 		i = 0;
// 		while (s1[i] != '\0' && s1)
// 		{
// 			d[i] = s1[i];
// 			i++;
// 		}
// 		k = 0;
// 		while (s2[k] != '\0')
// 		{
// 			d[i + k] = s2[k];
// 			k++;
// 		}
// 		d[i + k] = 0;
// 		free(s1);
// 		return (d);
// }

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
	if (r[i] == ch)
		return (&r[i]);
	while (r[i] != '\0')
	{
		if (r[i] == ch)
			return (&r[i]);
		i++;
	}
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