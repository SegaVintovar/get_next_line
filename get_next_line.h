/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 15:35:29 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/29 16:17:46 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *c);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*join_help(char *s1, const char *s2, size_t len1, size_t len2);
char	*line_extractor(char *line);
char	*buffer_extractor(char *line);
char	*reading_func(int fd);

#endif