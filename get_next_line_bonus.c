/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:55:44 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/17 17:45:48 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_join(char *statica, int fd)
{
	char	*buffer;
	char	*temp;
	int		num_byte;

	if (!statica)
		statica = ft_calloc(1, sizeof(char));
	if (!statica)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	num_byte = 1;
	while (!ft_strchr(statica, '\n') && num_byte > 0)
	{
		num_byte = read(fd, buffer, BUFFER_SIZE);
		if (num_byte >= 0)
			buffer[num_byte] = '\0';
		temp = ft_strjoin(statica, buffer);
		if (!temp)
			return (free(buffer), NULL);
		statica = temp;
	}
	if (num_byte < 0)
		return (free(statica), free(buffer), NULL);
	return (free(buffer), statica);
}

char	*ft_get_line(char *statica)
{
	int		i;

	if (!statica || !statica[0])
		return (NULL);
	i = 0;
	while (statica[i] && statica[i] != '\n')
		i++;
	if (statica[i] == '\n')
		return (ft_substr(statica, 0, i + 1));
	return (ft_substr(statica, 0, i));
}

char	*ft_update_static(char *statica)
{
	char	*new_static;
	int		i;
	int		j;

	i = 0;
	while (statica[i] && statica[i] != '\n')
		i++;
	if (!statica[i])
	{
		free(statica);
		return (NULL);
	}
	new_static = ft_calloc(ft_strlen(statica) - i, sizeof(char));
	if (!new_static)
		return (NULL);
	j = 0;
	while (statica[++i])
		new_static[j++] = statica[i];
	free(statica);
	return (new_static);
}

char	*get_next_line(int fd)
{
	static char	*statica[FD_MAX];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	statica[fd] = ft_read_join(statica[fd], fd);
	if (!statica[fd])
		return (NULL);
	line = ft_get_line(statica[fd]);
	temp = ft_update_static(statica[fd]);
	statica[fd] = temp;
	return (line);
}
/*int main(void)
{
	int fd1 = open("text.txt", O_RDONLY);
	int fd2 = open("text1.txt", O_RDONLY);
	char *line1;
	char *line2;

	if (fd1 < 0 || fd2 < 0)
		return (printf("Error abriendo archivos\n"), 1);

	while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
	{
		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("FD2: %s", line2);
			free(line2);
		}
	}

	close(fd1);
	close(fd2);
	return (0);
}*/
