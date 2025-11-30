/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 10:45:58 by vs            #+#    #+#                 */
/*   Updated: 2025/11/30 13:13:02 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || s1[0] == 0)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	if (len1 == 0 && len2 == 0)
		return (free(s1), NULL);
	result = join_help(s1, s2, len1, len2);
	if (result && result[0] == 0)
		return (free(s1), free(result), NULL);
	return (result);
}

char	*join_help(char *s1, const char *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	p;
	char	*result;

	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	p = 0;
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
	if (s1)
		free(s1);
	return (result);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	if (!c)
		return (0);
	len = 0;
	while (c && c[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	ch;

	if (s == NULL)
		return (NULL);
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
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (start > ft_strlen(s))
		return (NULL);
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	d = malloc(len + 1);
	if (!d)
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
