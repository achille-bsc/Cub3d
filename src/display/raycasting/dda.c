/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 02:08:23 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 12:11:10 by lvan-bre         ###   ########.fr       */
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

void	rays_dist_calculator(t_data *data, t_camera *cam, t_camera **door,
	char **map)
{
	int	i;

	i = data->nmb_of_doors - 1;
	while (!cam->hit)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->map_x += cam->step_x;
			cam->side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->map_y += cam->step_y;
			cam->side = 1;
		}
		if (map[cam->map_y][cam->map_x] != '0'
			&& !is_voided_door(map[cam->map_y][cam->map_x]))
			cam->hit = true;
		if (is_voided_door(map[cam->map_y][cam->map_x]))
			ft_memcpy(door[i--], cam, sizeof(t_camera));
	}
}

int	get_nmb_of_doors(t_camera *cam, char **map)
{
	t_camera	dummy;
	int			doors;

	ft_memcpy(&dummy, cam, sizeof(t_camera));
	doors = 0;
	while (1)
	{
		if (dummy.side_dist_x < dummy.side_dist_y)
		{
			dummy.side_dist_x += dummy.delta_dist_x;
			dummy.map_x += dummy.step_x;
		}
		else
		{
			dummy.side_dist_y += dummy.delta_dist_y;
			dummy.map_y += dummy.step_y;
		}
		if (map[dummy.map_y][dummy.map_x] != '0'
			&& !is_voided_door(map[dummy.map_y][dummy.map_x]))
			return (doors);
		if (is_voided_door(map[dummy.map_y][dummy.map_x]))
			doors++;
	}
}
