/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:21:35 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/23 00:47:01 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ctype.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	int	c = 'a';

// 	printf("le resultat de ma fonction est : %c\n",ft_toupper(c));
// 	printf("le resultat de la fonction d'origine est : %c\n",toupper(c));
// 	return (0);
// }
