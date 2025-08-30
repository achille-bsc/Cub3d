/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:19:51 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 06:22:30 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (src == NULL)
		return (-1);
	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int main(void)
// {
// 	char buffer[150] = "une licorne";
// 	char bbuffer[150] = "une licornasse";
// 	size_t res = ft_strlcpy(buffer, bbuffer, 10);

// 	printf("le resultat de ma fonction est '%ld'\n", res);
// 	return (0);
// }
