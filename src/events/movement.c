/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:24:19 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/07 22:37:47 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] + player->vec[X] * MV_SPEED * player->sprint;
	new_y = player->pos[Y] + player->vec[Y] * MV_SPEED * player->sprint;
	if (map.map[(int)player->pos[Y]][(int)new_x]
		&& map.map[(int)player->pos[Y]][(int)new_x] != '1'
		&& map.map[(int)player->pos[Y]][(int)new_x] != ' ')
		player->pos[X] = new_x;
	if (map.map[(int)new_y][(int)player->pos[X]]
		&& map.map[(int)new_y][(int)player->pos[X]] != '1'
		&& map.map[(int)new_y][(int)player->pos[X]] != ' ')
		player->pos[Y] = new_y;
}

static void	move_backward(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] - player->vec[X] * MV_SPEED * player->sprint;
	new_y = player->pos[Y] - player->vec[Y] * MV_SPEED * player->sprint;
	if (map.map[(int)player->pos[Y]][(int)new_x]
		&& map.map[(int)player->pos[Y]][(int)new_x] != '1'
		&& map.map[(int)player->pos[Y]][(int)new_x] != ' ')
		player->pos[X] = new_x;
	if (map.map[(int)new_y][(int)player->pos[X]]
		&& map.map[(int)new_y][(int)player->pos[X]] != '1'
		&& map.map[(int)new_y][(int)player->pos[X]] != ' ')
		player->pos[Y] = new_y;
}

static void	move_left(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] + player->vec[Y] * MV_SPEED * player->sprint;
	new_y = player->pos[Y] - player->vec[X] * MV_SPEED * player->sprint;
	if (map.map[(int)player->pos[Y]][(int)new_x]
		&& map.map[(int)player->pos[Y]][(int)new_x] != '1'
		&& map.map[(int)player->pos[Y]][(int)new_x] != ' ')
		player->pos[X] = new_x;
	if (map.map[(int)new_y][(int)player->pos[X]]
		&& map.map[(int)new_y][(int)player->pos[X]] != '1'
		&& map.map[(int)new_y][(int)player->pos[X]] != ' ')
		player->pos[Y] = new_y;
}

static void	move_right(t_player *player, t_map map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos[X] - player->vec[Y] * MV_SPEED * player->sprint;
	new_y = player->pos[Y] + player->vec[X] * MV_SPEED * player->sprint;
	if (map.map[(int)player->pos[Y]][(int)new_x]
		&& map.map[(int)player->pos[Y]][(int)new_x] != '1'
		&& map.map[(int)player->pos[Y]][(int)new_x] != ' ')
		player->pos[X] = new_x;
	if (map.map[(int)new_y][(int)player->pos[X]]
		&& map.map[(int)new_y][(int)player->pos[X]] != '1'
		&& map.map[(int)new_y][(int)player->pos[X]] != ' ')
		player->pos[Y] = new_y;
}

void	player_move(t_map map, t_player *player, t_movement move)
{
	if (move.sprint)
		player->sprint = 2;
	else
		player->sprint = 1;
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
