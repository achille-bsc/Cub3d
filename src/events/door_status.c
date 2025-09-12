/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 04:02:53 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/12 04:52:58 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	ifs(char c)
{
	if (c == 'q')
		return ('w');
	else if (c == 'w')
		return ('e');
	else if (c == 'e')
		return ('r');
	else if (c == 'r')
		return ('O');
	if (c == 'Q')
		return ('W');
	else if (c == 'W')
		return ('E');
	else if (c == 'E')
		return ('R');
	else if (c == 'R')
		return ('C');
	else
		return (c);
}

void	change_door_status(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			map->map[y][x] = ifs(map->map[y][x]);
			x++;
		}
		y++;
	}
}
