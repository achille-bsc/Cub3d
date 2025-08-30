/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:10:01 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:40:04 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (true);
	return (false);
}

// int main(void)
// {
// 	int	ch = '1';

// 	printf("le resultat de ma fonction est %d\n", ft_isalpha(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isalpha(ch));
// 	return (0);
// }
