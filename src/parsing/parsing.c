/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:43:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/14 22:04:01 by lvan-bre         ###   ########.fr       */
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

static bool	colors_verification(t_data *data)
{
	char	**color;
	int		i;

	i = 0;
	while (i < 2)
	{
		check_color_chars(data, data->colors[i]);
		color = ft_split(data->colors[i], ',');
		if (!color)
			return (false);
		if (ft_darraylen(color) != 3)
			return (ft_printf(_RGB_FORMAT), ft_freedarray(color), false);
		parse_colors(data, color, i);
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
		return (exit_w_code(1, data), false);
	data->win->fov_factor = tan((FOV * M_PI / 180.0) / 2);
	if (!dispatch_data(data, fullfile) || !colors_verification(data)
		|| !map_parsing(data, data->map.map))
		return (ft_freedarray(fullfile), exit_w_code(1, data), false);
	return (ft_freedarray(fullfile), true);
}
