/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:24:19 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/04 18:13:50 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turning_cam(t_player *player, t_movement move)
{
	if (move.dir_left)
	{
		player->dir -= ROT_SPEED;
		if (player->dir < 0)
			player->dir += 2 * M_PI;
	}
	if (move.dir_right)
	{
		player->dir += ROT_SPEED;
		if (player->dir > 2 * M_PI)
			player->dir -= 2 * M_PI;
	}
	printf("%f\n", player->dir);
}

static void	move_forward(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] + player->vec[X] * MV_SPEED;
	new_y = player->pos[Y] + player->vec[Y] * MV_SPEED;
	if (map.map[(int)new_y][(int)new_x] != '1')
	{
		player->pos[X] = new_x;
		player->pos[Y] = new_y;
	}
}

static void	move_backward(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] - player->vec[X] * MV_SPEED;
	new_y = player->pos[Y] - player->vec[Y] * MV_SPEED;
	if (map.map[(int)new_y][(int)new_x] != '1')
	{
		player->pos[X] = new_x;
		player->pos[Y] = new_y;
	}
}

static void	move_left(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] + player->vec[Y] * MV_SPEED;
	new_y = player->pos[Y] - player->vec[X] * MV_SPEED;
	if (map.map[(int)new_y][(int)new_x] != '1')
	{
		player->pos[X] = new_x;
		player->pos[Y] = new_y;
	}
}

static void	move_right(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] - player->vec[Y] * MV_SPEED;
	new_y = player->pos[Y] + player->vec[X] * MV_SPEED;
	if (map.map[(int)new_y][(int)new_x] != '1')
	{
		player->pos[X] = new_x;
		player->pos[Y] = new_y;
	}
}

void	player_move(t_map map, t_player *player, t_movement move)
{
	if (move.forward)
		move_forward(player, map);
	if (move.backward)
		move_backward(player, map);
	if (move.left)
		move_left(player, map);
	if (move.right)
		move_right(player, map);
	turning_cam(player, move);
}
