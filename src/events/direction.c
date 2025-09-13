/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:42:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 08:09:57 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mouse_handling(t_player *player, t_window *win)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(win->mlx, win->window, &x, &y);
	player->dir += (double)(((x - player->mouse_last_pos) / 500.0));
	if (player->dir > 2 * M_PI)
		player->dir -= 2 * M_PI;
	else if (player->dir < 0)
		player->dir += 2 * M_PI;
	if (x >= WIDTH - 10 || x <= 10)
	{
		mlx_mouse_move(win->mlx, win->window, WIDTH / 2, y);
		player->mouse_last_pos = WIDTH / 2;
	}
	else
		player->mouse_last_pos = x;
}

void	turning_cam(t_window *win, t_player *player, t_movement move)
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
	mouse_handling(player, win);
	player->vec[X] = cos(player->dir);
	player->vec[Y] = sin(player->dir);
}
