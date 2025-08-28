/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:43:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/08/28 21:01:32 by lvan-bre         ###   ########.fr       */
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
		ft_printf(_FILE, map_path);
		return (false);
	}
	buffer = get_all_file(fd);
	close(fd);
	if (!buffer)
		return (ft_printf(_EMPTY_FILE), free(data), false);
	fullfile = ft_split(buffer, '\n');
	if (!fullfile)
		return (free(buffer), false);
	if (!dispatch_data(data, fullfile))
		return (free_pars_info(data), ft_freeall("%s%d%m", &buffer, &fullfile,
				&data), false);
	return (ft_freeall("%s%d", &buffer, &fullfile), true);
}
