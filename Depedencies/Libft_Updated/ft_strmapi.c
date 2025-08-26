/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:45:40 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:07:29 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buffer;

	i = 0;
	buffer = ft_calloc(ft_strlen(s) + 1);
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
