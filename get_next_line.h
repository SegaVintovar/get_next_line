#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *c);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*join_help(char *s1, const char *s2, size_t len1, size_t len2);


#endif