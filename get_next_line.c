/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:28:34 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/07 15:50:25 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

# define BUFFER_SIZE 10

char	*ft_read_join(char *statica, int fd)
{
	char	*buffer;
	int		num_byte;
	char	*line;

	line = statica;
	while (ft_strchr(line, '\n') == NULL)
	{
		buffer = malloc(BUFFER_SIZE +1 , 1);
		if (!buffer)
			return (NULL);
		num_byte= read(fd, buffer, BUFFER_SIZE);
		if (num_byte == 0)
			break;
		if (num_byte < 0)
			return(free(buffer), NULL);
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	return(line);
}
char	*get_next_line(int fd)
{
	static char	*result;
	char		*str;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!result)
	{
		result = malloc(1 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
	}
	str = ft_read_join(result, fd);
	if(!str)
		return (0);
	return (str);
}

int	main()
{
	char *line = NULL;
	int fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
	//	free(line);
	}
	return 0;
}
