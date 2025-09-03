/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:24:19 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/04 01:36:04 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turning_cam(t_player *player, t_movement move)
{
	if (move.dir_left)
	{
		player->dir[X] -= ROT_SPEED;
		if (player->dir[X] < 0)
			player->dir[X] += 2 * M_PI;
	}
	if (move.dir_right)
	{
		player->dir[X] += ROT_SPEED;
		if (player->dir[X] > 2 * M_PI)
			player->dir[X] -= 2 * M_PI;
	}
	printf("%f\n", player->dir[X]);
}

void	movements_handling_2(t_map map, t_player *player, t_movement move)
{
	double	mv[2];

	if (move.forward)
	{
		mv[X] = -sin(player->dir[X]);
		mv[Y] = cos(player->dir[X]);
		if (map.map[(int)(player->pos[Y] - (mv[Y] * MV_SPEED * 2))]
			[(int)(player->pos[X] - (mv[X] * MV_SPEED))] != '1')
		{
			player->pos[X] -= mv[X] * MV_SPEED;
			player->pos[Y] -= mv[Y] * MV_SPEED;
		}
	}
	if (move.backward)
	{
		mv[X] = sin(player->dir[X]);
		mv[Y] = -cos(player->dir[X]);
		if (map.map[(int)(player->pos[Y] - (MV_SPEED * mv[Y] * 2))]
		[(int)(player->pos[X] - (MV_SPEED * mv[X]))] != '1')
		{
			player->pos[X] -= mv[X] * MV_SPEED;
			player->pos[Y] -= mv[Y] * MV_SPEED;
		}
	}
	turning_cam(player, move);
}

void	movements_handling(t_map map, t_player *player, t_movement move)
{
	double	mv[2];

	if (move.right)
	{
		mv[X] = cos(player->dir[X]);
		mv[Y] = sin(player->dir[X]);
		if (map.map[(int)(player->pos[Y] + mv[Y] * MV_SPEED)]
				[(int)(player->pos[X] + (mv[X] * MV_SPEED * 2))] != '1')
		{
			player->pos[X] += mv[X] * MV_SPEED;
			player->pos[Y] += mv[Y] * MV_SPEED;
		}
	}
	if (move.left)
	{
		mv[X] = cos(player->dir[X]);
		mv[Y] = sin(player->dir[X]);
		if (map.map[(int)(player->pos[Y] - (mv[Y] * MV_SPEED))]
				[(int)(player->pos[X] - (mv[X] * MV_SPEED * 2))] != '1')
		{
			player->pos[X] -= mv[X] * MV_SPEED;
			player->pos[Y] -= mv[Y] * MV_SPEED;
		}
	}
	movements_handling_2(map, player, move);
}

