/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:08:29 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:08:11 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*buffer;
	size_t	trimmed;

	while (ft_strchr(set, *s1) && *s1)
		s1++;
	trimmed = ft_strlen(s1);
	while (ft_strchr(set, s1[trimmed - 1]) && trimmed > 0)
		trimmed--;
	buffer = ft_calloc(trimmed + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, trimmed + 1);
	return (buffer);
}
