/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:42:57 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/20 01:48:42 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmchars(char *str, char c)
{
	int		i;
	char	*buffer;

	i = 0;
	while (str[i] == c)
		i++;
	buffer = ft_strdup(str + i);
	free(str);
	return (buffer);
}
