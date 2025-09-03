/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 03:26:53 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/03 16:25:36 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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
