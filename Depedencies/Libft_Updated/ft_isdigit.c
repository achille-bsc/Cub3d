/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:06:03 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:39:27 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

// int main(void)
// {
// 	int	ch = 'a';

// 	printf("le resultat de ma fonction est %d\n", ft_isdigit(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isdigit(ch));
// 	return (0);
// }
