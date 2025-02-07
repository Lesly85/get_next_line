#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*# ifndef BUFFER_SIZE 10
#  define BUFFER_SIZE
# endif
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
