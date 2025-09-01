/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:43:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/01 14:40:19 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		data->rgb[i] = (rgb[RED] << 16) + (rgb[GREEN] << 8) + rgb[BLUE];
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
	if (!dispatch_data(data, fullfile) || !colors_verification(data)
		|| !map_parsing(data, data->map.map))
		return (free_pars_info(data), ft_freeall("%d%d%d%m", &fullfile,
				&data->map.map, &data->map.dummy, &data), false);
	return (ft_freedarray(fullfile), true);
}
