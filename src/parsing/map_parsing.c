/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:09:08 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/04 01:32:49 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	player_four_dirs(t_data *data)
{
	int	posx;
	int	posy;

	posx = (int)data->player->pos[X];
	posy = (int)data->player->pos[Y];
	if (posx > (int)ft_strlen(data->map.map[posy + 1])
		|| posx > (int)ft_strlen(data->map.map[posy - 1]))
		return (ft_printf(_OPEN_MAP, posx, posy), false);
	return (true);
}

static bool	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !data->map.dummy[y] || !data->map.dummy[y][x])
		return (ft_printf(_OPEN_MAP, x, y), false);
	else if (data->map.dummy[y][x] == '1' || data->map.dummy[y][x] == 'd')
		return (true);
	if (data->map.dummy[y][x] == '0' || data->map.dummy[y][x] == ' ')
		data->map.dummy[y][x] = 'd';
	if (!flood_fill(data, x + 1, y))
		return (false);
	if (!flood_fill(data, x, y + 1))
		return (false);
	if (!flood_fill(data, x - 1, y))
		return (false);
	if (!flood_fill(data, x, y - 1))
		return (false);
	return (true);
}

static void	add_to_spawn(t_data *data, int i, int j, char c)
{
	data->player = ft_calloc(sizeof(t_player));
	data->player->pos[X] = j + 0.5;
	data->player->pos[Y] = i + 0.5;
	if (c == 'N')
		data->player->dir[X] = M_PI / 2;
	else if (c == 'S')
		data->player->dir[X] = 3 * M_PI / 2;
	else if (c == 'E')
		data->player->dir[X] = M_PI;
	else if (c == 'W')
		data->player->dir[X] = 2 * M_PI;
	data->map.map[i][j] = '0';
}

static bool	check_chars(t_data *data, char **map)
{
	int	spawn_found;
	int	i;
	int	j;

	i = -1;
	spawn_found = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!is_map(map[i][j]))
				return (ft_printf(_MAP_CHAR, map[i][j]), false);
			if (is_spawn(map[i][j]))
			{
				add_to_spawn(data, i, j, map[i][j]);
				spawn_found++;
			}
		}
	}
	if (spawn_found == 0)
		return (ft_printf(_NO_SPAWN), false);
	else if (spawn_found > 1)
		return (ft_printf(_MULTI_PLAYER), false);
	return (true);
}

bool	map_parsing(t_data *data, char **map)
{
	if (!check_chars(data, map))
		return (false);
	data->map.dummy = ft_arraydup(map);
	if (!data->map.dummy)
		return (false);
	if (!player_four_dirs(data)
		|| !flood_fill(data, data->player->pos[X], data->player->pos[Y]))
		return (false);
	return (true);
}
