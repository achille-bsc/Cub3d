/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 03:26:53 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/08/28 04:17:13 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skipchar(char *src, int offset, char skiped)
{
	char	*buffer;
	int		i;

	i = offset;
	while (src[i] == skiped)
		i++;
	buffer = ft_strdup(src + i);
	return (buffer);
}
