/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesescob <lesescob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:28:34 by lesescob          #+#    #+#             */
/*   Updated: 2025/01/29 19:03:54 by lesescob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_join(char *statica, int fd)
{
	char	*buffer;
	char	*temporanea;
	int		num_byte;
	char	*line;

	line = statica;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	while (ft_strchr(line, "\n") == 0)
	{

	}
}
char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}
