/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:43:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/08/28 06:30:47 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


bool	parser(t_data *data, char *map_path)
{
	char	**fullfile;
	char	*buffer;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(FILE, map_path);
		return (false);
	}
	buffer = get_all_file(fd);
	close(fd);
	if (!buffer)
		return (false);
	fullfile = ft_split(buffer, '\n');
	if (!fullfile)
		return (free(buffer), false);
	if (!parse_data(data, fullfile))
		return (ft_freeall("%s%d%m", &buffer, &fullfile, &data),
			free_str_array(data->colors), free_str_array(data->text), false);
	return (ft_freeall("%s%d", &buffer, &fullfile), true);
}
