/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leane <leane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:09:08 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/11 01:13:36 by leane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_ff_both_x(char **dummy, int x, int y)
{
	int	size_up;
	int	size_down;

	if (y >= 1 && dummy[y - 1])
		size_up = ft_strlen(dummy[y - 1]);
	if (dummy[y + 1])
		size_down = ft_strlen(dummy[y + 1]);
	if (x + 1 > size_up || x + 1 > size_down)
		return (false);
	return (true);
}

static bool	flood_fill(t_data *data, int x, int y, char **dummy)
{
	if (x < 0 || y < 0 || !dummy[y] || !dummy[y][x])
		return (ft_printf(_OPEN_MAP, x, y), false);
	else if (dummy[y][x] == '1' || dummy[y][x] == 'd')
		return (true);
	if (dummy[y][x] == ' ')
		data->map.map[y][x] = '0';
	if (!check_ff_both_x(dummy, x, y))
		return (ft_printf(_OPEN_MAP, x, y), false);
	if (dummy[y][x] == '0' || dummy[y][x] == ' '
		|| dummy[y][x] == 'C' || dummy[y][x] == 'O')
		dummy[y][x] = 'd';
	if (!flood_fill(data, x + 1, y, dummy))
		return (false);
	if (!flood_fill(data, x, y + 1, dummy))
		return (false);
	if (!flood_fill(data, x - 1, y, dummy))
		return (false);
	if (!flood_fill(data, x, y - 1, dummy))
		return (false);
	return (true);
}

static void	add_to_spawn(t_data *data, int i, int j, char c)
{
	if (!data->player)
		data->player = ft_calloc(sizeof(t_player));
	data->player->pos[X] = j + 0.5;
	data->player->pos[Y] = i + 0.5;
	data->player->spawn[X] = data->player->pos[X];
	data->player->spawn[Y] = data->player->pos[Y];
	if (c == 'N')
		data->player->dir = 3 * M_PI / 2;
	else if (c == 'S')
		data->player->dir = M_PI / 2;
	else if (c == 'W')
		data->player->dir = M_PI;
	else if (c == 'E')
		data->player->dir = 2 * M_PI;
	data->player->spawn[DIRX] = data->player->dir;
	data->player->spawn[DIRZ] = data->player->dirz;
	data->map.map[i][j] = '0';
	data->player->vec[Y] = sin(data->player->dir);
	data->player->vec[X] = cos(data->player->dir);
	data->player->plane[X] = -data->player->vec[Y] * data->win->fov_factor;
	data->player->plane[Y] = data->player->vec[X] * data->win->fov_factor;
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
	char	**dummy;

	if (!check_chars(data, map))
		return (false);
	dummy = ft_arraydup(map);
	if (!dummy)
		return (false);
	if (!player_four_dirs(data)
		|| !flood_fill(data, data->player->pos[X], data->player->pos[Y], dummy))
		return (ft_freedarray(dummy), false);
	land_height(data, data->map.map);
	get_longer_str(data, data->map.map);
	return (ft_freedarray(dummy), true);
}
