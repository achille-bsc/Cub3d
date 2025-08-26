/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:38:07 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/07 17:45:40 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_all_file(int fd)
{
	char	*buffer;
	char	*line;

	buffer = NULL;
	line = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			return (get_next_line(-1), line);
		line = ft_strjoining(line, buffer);
		free(buffer);
		if (!line)
			return (get_next_line(-1), NULL);
	}
}
