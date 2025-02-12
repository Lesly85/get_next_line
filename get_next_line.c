/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:28:34 by lesescob          #+#    #+#             */
/*   Updated: 2025/02/12 18:11:27 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_join(char *statica, int fd)
{
	char	*buffer;
	char	*temp;
	int		num_byte;

	if (!statica)
		statica = ft_calloc(1, sizeof(char));
	if (!statica)
		return (NULL);// sempre meglio un controllo in piu
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);// il free e' ridondante perche se non ce il buffer allora non ha bisogno del free
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
	static char	*statica;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	statica = ft_read_join(statica, fd);
	if (!statica)
		return (NULL);
	line = ft_get_line(statica);
	temp = ft_update_static(statica);
	statica = temp;
	return (line);
}

/*int main()
{
	char *line;
	int fd = open("text.txt", O_RDONLY);

	if (fd < 0)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);  // Libera la memoria después de cada línea
	}
	close(fd);  // Cierra el archivo cuando terminamos
	return (0);
}*/
