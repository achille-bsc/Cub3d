/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:47:28 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 13:33:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (true);
	return (false);
}

bool	is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static int	*search_for_land(char *map)
{
	int		*res;
	bool	begin;
	int		i;

	i = 0;
	begin = true;
	res = ft_calloc(sizeof(int) * 2);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
		{
			if (begin)
			{
				res[BEGIN] = i;
				begin = false;
			}
			res[END] = i;
		}
		i++;
	}
	if (res[BEGIN] == 0)
		res[BEGIN] = ft_strlen(map);
	return (res);
}

void	get_longer_str(t_data *data, char **map)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = search_for_land(map[i]);
	data->map.extremities_x[BEGIN] = tmp[BEGIN];
	data->map.extremities_x[END] = tmp[END];
	free(tmp);
	while (map[++i])
	{
		tmp = search_for_land(map[i]);
		if (tmp[BEGIN] < data->map.extremities_x[BEGIN])
			data->map.extremities_x[BEGIN] = tmp[BEGIN];
		if (tmp[END] > data->map.extremities_x[END])
			data->map.extremities_x[END] = tmp[END];
		free(tmp);
	}
	data->map.size_x = data->map.extremities_x[END]
		- data->map.extremities_x[BEGIN];
}

void	land_height(t_data *data, char **map)
{
	bool	begin;
	int		y;
	int		x;

	begin = true;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0')
			{
				if (begin)
				{
					data->map.extremities_y[BEGIN] = y;
					begin = false;
				}
				data->map.extremities_y[END] = y;
				break ;
			}
		}
	}
	data->map.size_y = data->map.extremities_y[END]
		- data->map.extremities_y[BEGIN];
}
