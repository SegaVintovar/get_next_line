/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:58 by vs                #+#    #+#             */
/*   Updated: 2025/11/17 10:49:01 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1, char *s2)
{
        size_t  len_s;
        size_t  i;
        size_t  p;
        char    *d;

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

size_t  ft_strlen(const char *c)
{
        size_t  len;

        len = 0;
        while (c[len] != '\0')
                len ++;
        return (len);
}

