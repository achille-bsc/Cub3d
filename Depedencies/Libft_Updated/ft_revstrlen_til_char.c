/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstrlen_til_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:47:42 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/21 03:49:34 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_revstrlen_til_char(char *src, char c)
{
	int	i;

	i = ft_strlen(src);
	while (i > 0 && src[i] != c)
		i--;
	return (i);
}
