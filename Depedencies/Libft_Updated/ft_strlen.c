/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:02:43 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/17 16:59:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

// int main(void)
// {
// 	const char ch[] = "";

// 	printf("le resultat de ma fonction est %zu\n", ft_strlen(ch));
// 	printf("le resultat de la fonction d'origine est %lu\n", strlen(ch));
// 	return (0);
// }
