/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:42:13 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/19 02:37:19 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = s;
	while (n-- > 0)
		*a++ = 0;
}

// int main(void)
// {
// 	char buffer[150] = "je suis une licornasse";
// 	char bbuffer[150] = "je suis une licornasse";

// 	ft_bzero(buffer + 5, 10);
// 	bzero(bbuffer + 5, 10);
// 	printf("le resultat de ma fonction est '%s'\n", buffer);
// 	printf("le resultat de la fonction d'origine est '%s'\n", bbuffer);
// 	return (0);
// }
