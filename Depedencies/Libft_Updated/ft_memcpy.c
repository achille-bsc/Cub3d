/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:37:44 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/04 14:12:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (dst == 0 && source == 0)
		return (NULL);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}

// int main(void)
// {
// 	const char src[28] = "hello world";
// 	char dest[28] = "oeaioea";

// 	ft_memcpy(dest, src, 10);
// 	printf("le resultat de ma fonction est %s\n", dest);
// 	return (0);
// }
