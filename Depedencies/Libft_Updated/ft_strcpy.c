/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 04:28:07 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 04:40:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	if (src == NULL)
		return (-1);
	len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main(void)
// {
// 	char buffer[150];
// 	size_t res = ft_strcpy(buffer, NULL);

// 	printf("le resultat de ma fonction est '%ld'\n, buffer : %s", res, buffer);
// 	return (0);
// }
