/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnchrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:19 by sellith           #+#    #+#             */
/*   Updated: 2025/05/21 06:29:29 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrnchrlen(char *src, char c, int len)
{
	int	i;

	if (!src)
		return (0);
	i = ft_strlen(src);
	if (i > len)
		i = len;
	while (i > 0 && src[i] != c)
		i--;
	return (i);
}
