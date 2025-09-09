/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:09:43 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/09 00:54:16 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	minimap_display(t_data *data)
{
	if (data->move.display_minimap)
		data->move.display_minimap = false;
	else
		data->move.display_minimap = true;
	return (0);
}

int	debug_info(t_data *data)
{
	if (data->move.debug)
		data->move.debug = false;
	else
		data->move.debug = true;
	return (0);
}

int	re_center_cam(t_data *data)
{
	data->player->dir = data->player->spawn[DIRX];
	data->player->dirz = data->player->spawn[DIRZ];
	data->player->vec[Y] = sin(data->player->dir);
	data->player->vec[X] = cos(data->player->dir);
	data->player->plane[X] = -data->player->vec[Y] * data->win->fov_factor;
	data->player->plane[Y] = data->player->vec[X] * data->win->fov_factor;
	return (0);
}

int	respawn(t_data *data)
{
	data->player->pos[X] = data->player->spawn[X];
	data->player->pos[Y] = data->player->spawn[Y];
	re_center_cam(data);
	return (0);
}

int	door_action(double pos[2], char **map)
{
	if (map[(int)pos[Y]][(int)(pos[X] + 0.40)] == 'C')
		map[(int)pos[Y]][(int)(pos[X] + 0.40)] = 'O';
	else if (map[(int)pos[Y]][(int)(pos[X] + 0.40)] == 'O')
		map[(int)pos[Y]][(int)(pos[X] + 0.40)] = 'C';
	if (map[(int)pos[Y]][(int)(pos[X] - 0.40)] == 'C')
		map[(int)pos[Y]][(int)(pos[X] - 0.40)] = 'O';
	else if (map[(int)pos[Y]][(int)(pos[X] - 0.40)] == 'O')
		map[(int)pos[Y]][(int)(pos[X] - 0.40)] = 'C';
	if (map[(int)(pos[Y] + 0.40)][(int)(pos[X])] == 'C')
		map[(int)(pos[Y] + 0.40)][(int)(pos[X])] = 'O';
	else if (map[(int)(pos[Y] + 0.40)][(int)(pos[X])] == 'O')
		map[(int)(pos[Y] + 0.40)][(int)(pos[X])] = 'C';
	if (map[(int)(pos[Y] - 0.40)][(int)(pos[X])] == 'C')
		map[(int)(pos[Y] - 0.40)][(int)(pos[X])] = 'O';
	else if (map[(int)(pos[Y] - 0.40)][(int)(pos[X])] == 'O')
		map[(int)(pos[Y] - 0.40)][(int)(pos[X])] = 'C';
	return (0);
}
