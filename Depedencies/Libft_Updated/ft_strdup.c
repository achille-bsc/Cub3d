/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:55:04 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:07:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = ft_calloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
