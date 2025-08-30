/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:43:23 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:08:24 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len <= ft_strlen(s) - start)
		buffer = ft_calloc(len++ + 1);
	else
	{
		buffer = ft_calloc(ft_strlen(s) - start + 1);
		len = (ft_strlen(s) - start + 1);
	}
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, (s + start), len);
	return (buffer);
}

/*int	main()
{
 	char	v1[] = "hola";
 	char	*v2;
 	v2 = ft_substr(v1, 0, 10);
 	printf("%s / %s\n", v1, v2);
}*/
