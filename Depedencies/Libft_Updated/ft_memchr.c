/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:33:44 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/24 00:28:52 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*st;

	st = (char *)s;
	while (n > 0)
	{
		if (*st == (char)c)
			return (st);
		st++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*s1 = "bonjour";

// 	printf("%p\n", ft_memchr(s1, 'o', 7));
// 	printf("%p", memchr(s1, 'o', 7));
// 	return (0);
// }
