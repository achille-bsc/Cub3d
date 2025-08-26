/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:29:53 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:08:02 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *sent, int size)
{
	char	*buffer;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(sent);
	if (len > size)
		len = size;
	buffer = ft_calloc(len + 1);
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		buffer[i] = sent[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
