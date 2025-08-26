/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:53:40 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/21 20:29:23 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char buffer[150] = "une licornasse";
// 	char bbuffer[150] = "une licornasse";

// 	ft_memset(buffer, 'e', 1);
// 	memset(bbuffer, 'e', 1);
// 	printf("le resultat de ma fonction est '%s'\n", buffer);
// 	printf("le resultat de la fonction d'origine est '%s'\n", bbuffer);
// 	return (0);
// }
