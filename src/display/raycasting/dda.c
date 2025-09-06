/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 02:08:23 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 03:51:49 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_val_setter(t_player *player, t_camera *cam, int x)
{
	cam->cameraX = 2 * (x + 0.5) / (double)(WIDTH - 1) - 1;
	cam->rayDirX = player->vec[X] + player->plane[X] * cam->cameraX;
	cam->rayDirY = player->vec[Y] + player->plane[Y] * cam->cameraX;
	cam->mapX = (int)player->pos[X];
	cam->mapY = (int)player->pos[Y];
	if (cam->rayDirX != 0)
		cam->deltaDistX = fabs(1 / cam->rayDirX);
	else
		cam->deltaDistX = DBL_MAX;
	if (cam->rayDirY != 0)
		cam->deltaDistY = fabs(1 / cam->rayDirY);
	else
		cam->deltaDistY = DBL_MAX;
	// cam->sideDistX;
	// cam->sideDistY;
}

void	rays_dir_setter(t_camera *cam, double pos[2])
{
	if (cam->rayDirX < 0)
	{
		cam->stepX = -1;
		cam->sideDistX = (pos[X] - cam->mapX) * cam->deltaDistX;
	}
	else
	{
		cam->stepX = 1;
		cam->sideDistX = (cam->mapX + 1.0 - pos[X]) * cam->deltaDistX;
	}
	if (cam->rayDirY < 0)
	{
		cam->stepY = -1;
		cam->sideDistY = (pos[Y] - cam->mapY) * cam->deltaDistY;
	}
	else
	{
		cam->stepY = 1;
		cam->sideDistY = (cam->mapY + 1.0 - pos[Y]) * cam->deltaDistY;
	}
}

int	rays_calculator(t_camera *cam, t_data *data)
{
	bool	hit;
	int		side;

	hit = false;
	while (!hit)
	{
		if (cam->sideDistX < cam->sideDistY)
		{
			cam->sideDistX += cam->deltaDistX;
			cam->mapX += cam->stepX;
			side = 0;
		}
		else
		{
			cam->sideDistY += cam->deltaDistY;
			cam->mapY += cam->stepY;
			side = 1;
		}
		if (data->map.map[cam->mapY][cam->mapX] != '0')
			hit = true;
	}
	return (side);
}
