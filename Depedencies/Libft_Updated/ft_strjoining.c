/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoining.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:16:17 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:07:22 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoining(char *s1, char const *s2)
{
	char	*buffer;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
	{
		buffer = ft_strdup(s1);
		return (free(s1), buffer);
	}
	if (!s1 && !s2)
		return (NULL);
	buffer = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	free(s1);
	return (buffer);
}
