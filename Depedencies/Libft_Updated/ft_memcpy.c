/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:37:44 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 12:52:58 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_memcpy - Copies exactly size bytes from src to dest.
	Returns dest, or NULL if src/dest are invalid and size > 0.
	Undefined behavior if memory regions overlap.
*/
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	if (size == 0)
		return (dest);
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dst[i] = source[i];
		i++;
	}
	return ((void *)dst);
}

// int main(void)
// {
// 	const char src[28] = "hello world";
// 	char dest[28] = "oeaioea";

// 	ft_memcpy(dest, src, 10);
// 	printf("le resultat de ma fonction est %s\n", dest);
// 	return (0);
// }
