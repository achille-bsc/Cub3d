/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 04:28:20 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/23 00:35:27 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;
// 	size_t	l;

// 	i = 0;
// 	j = 0;
// 	while (i < size && dst[i] != '\0')
// 	size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;
// 	size_t	l;

// 	i = 0;
// 	j = 0;
// 	while (i < size && dst[i] != '\0')
// 		i++;
// 	k = i;
// 	if (size <= i || size == 0)
// 		return (ft_strlen(src) + size);
// 	l = ft_strlen(src);
// 	while (i < size - 1 && src[j] != '\0')
// 		dst[i++] = src[j++];
// 	dst[i] = '\0';
// 	return (k + l);
// }

// int	main(void)
// {
// 	char	src[] = "lorem ipsum";
// 	char	dest[] = "rrrrrr";
// 	char	src2[] = "lorem ipsum";
// 	char	dest2[] = "rrrrrr";
// 	size_t	res = ft_strlcat(dest, src, 15);
// 	size_t	res2 = strlcat(dest2, src2, 15);

// 	printf("le resultat de ma fonction est '%ld'\n", res);
// 	printf("le resultat de cat est '%s'\n", dest);
// 	printf("le resultat de la fonction d'origine est '%ld'\n", res2);
// 	printf("le resultat de cat original est '%s'\n", dest2);
// 	return (0);
// }
