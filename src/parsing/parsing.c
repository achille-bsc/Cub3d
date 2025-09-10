/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leane <leane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:43:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/10 23:41:22 by leane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	player_four_dirs(t_data *data)
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

static bool	is_rgb_value(int color)
{
	if (color < 0 || color > 255)
		return (ft_printf(_RGB_RANGE), false);
	return (true);
}

static bool	colors_verification(t_data *data)
{
	char	**color;
	int		rgb[3];
	int		i;

	i = 0;
	while (i < 2)
	{
		color = ft_split(data->colors[i], ',');
		if (!color)
			return (false);
		if (ft_darraylen(color) != 3)
			return (ft_printf(_RGB_FORMAT), ft_freedarray(color), false);
		rgb[RED] = ft_atoi(color[RED]);
		rgb[GREEN] = ft_atoi(color[GREEN]);
		rgb[BLUE] = ft_atoi(color[BLUE]);
		ft_freedarray(color);
		if (!is_rgb_value(rgb[RED]) || !is_rgb_value(rgb[GREEN])
			|| !is_rgb_value(rgb[BLUE]))
			return (false);
		data->rgb[i] = (255 << 24) + (rgb[RED] << 16) + (rgb[GREEN] << 8) + rgb[BLUE];
		i++;
	}
	data->rgb[PLAYER] = (255 << 16);
	return (true);
}

static char	**file_opening(char *map_path)
{
	char	**res;
	char	*buffer;
	int		fd;

	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		return (ft_printf(_FILE_EXTENSION), NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(_FILE, map_path);
		return (false);
	}
	buffer = get_all_file(fd);
	close(fd);
	if (!buffer)
		return (ft_printf(_EMPTY_FILE), NULL);
	res = ft_split(buffer, '\n');
	return (free(buffer), res);
}

bool	parser(t_data *data, char *map_path)
{
	char	**fullfile;

	fullfile = file_opening(map_path);
	if (!fullfile)
		return (free(data), false);
	data->win = ft_calloc(sizeof(t_window));
	if (!data->win)
		exit_w_code(1, data);
	data->win->fov_factor = tan((FOV * M_PI / 180.0) / 2);
	if (!dispatch_data(data, fullfile) || !colors_verification(data)
		|| !map_parsing(data, data->map.map))
		return (free_pars_info(data), ft_freeall("%d%d%m%m%m", &fullfile,
				&data->map.map, &data->player, &data->win, &data), false);
	return (ft_freedarray(fullfile), true);
}
