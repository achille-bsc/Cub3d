/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:41:10 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/24 00:32:04 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i--)
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
// 	const char src[28] = "hello world";
// 	char dest[28] = "oeaioea";
// 	const char src2[28] = "hello world";
// 	char dest2[28] = "oeaioea";

// 	ft_memmove(dest, src, 10);
// 	memmove(dest2, src2, 10);
// 	printf("le resultat de ma fonction est %s\n", dest);
// 	printf("le resultat de la fonction d'origine est %s\n", dest2);
// 	return (0);
// }
