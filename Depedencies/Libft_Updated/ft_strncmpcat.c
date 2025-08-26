/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmpcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:13:24 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/27 15:47:10 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmpcat(const char *s1, const char *s2, char *joined, size_t n)
{
	size_t	i;
	char	*buffer;
	char	c;

	i = 0;
	if (!s1 || !s2 || !joined)
		return (-1);
	buffer = ft_strjoin(s1, joined);
	while ((buffer[i] || s2[i]) && i < n)
	{
		if (buffer[i] != s2[i])
		{
			c = buffer[i];
			free(buffer);
			return ((const unsigned char)c - (const unsigned char)s2[i]);
		}
		i++;
	}
	free(buffer);
	return (0);
}
