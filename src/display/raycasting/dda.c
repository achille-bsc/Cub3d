/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 02:08:23 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 17:52:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_val_setter(t_player *player, t_camera *cam, int x)
{
	cam->camera_x = 2 * (x + 0.5) / (double)(WIDTH - 1) - 1;
	cam->ray_dir_x = player->vec[X] + player->plane[X] * cam->camera_x;
	cam->ray_dir_y = player->vec[Y] + player->plane[Y] * cam->camera_x;
	cam->map_x = (int)player->pos[X];
	cam->map_y = (int)player->pos[Y];
	if (cam->ray_dir_x != 0)
		cam->delta_dist_x = fabs(1 / cam->ray_dir_x);
	else
		cam->delta_dist_x = DBL_MAX;
	if (cam->ray_dir_y != 0)
		cam->delta_dist_y = fabs(1 / cam->ray_dir_y);
	else
		cam->delta_dist_y = DBL_MAX;
}

void	rays_dir_setter(t_camera *cam, double pos[2])
{
	if (cam->ray_dir_x < 0)
	{
		cam->step_x = -1;
		cam->side_dist_x = (pos[X] - cam->map_x) * cam->delta_dist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_dist_x = (cam->map_x + 1.0 - pos[X]) * cam->delta_dist_x;
	}
	if (cam->ray_dir_y < 0)
	{
		cam->step_y = -1;
		cam->side_dist_y = (pos[Y] - cam->map_y) * cam->delta_dist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->map_y + 1.0 - pos[Y]) * cam->delta_dist_y;
	}
}

int	rays_calculator(t_camera *cam, t_data *data)
{
	bool	hit;
	int		side;

	hit = false;
	while (!hit)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->map_x += cam->step_x;
			side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->map_y += cam->step_y;
			side = 1;
		}
		if (data->map.map[cam->map_y][cam->map_x] != '0')
			hit = true;
	}
	return (side);
}
