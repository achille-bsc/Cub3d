/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:18:29 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:39:03 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}

// int main(void)
// {
// 	int	ch = 32;

// 	printf("le resultat de ma fonction est %d\n", ft_isprint(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isprint(ch));
// 	return (0);
// }
