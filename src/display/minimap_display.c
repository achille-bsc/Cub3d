/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:55:30 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 17:35:35 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_minimap_tiles(t_data *data, t_window *win, int start[2])
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '0')
				put_tile(data->mini_texture[M_FLOOR], win,
					start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
			else if (data->map.map[y][x] == '1')
				put_tile(data->mini_texture[M_WALL], win,
					start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	dp_full_offset(t_data *data, t_window *win)
{
	int	start[2];

	start[X] = WIDTH - MINIMAP_SIZE_X + (MINIMAP_SIZE_X / 2)
		- data->player->pos[X] * TILE_SIZE;
	start[Y] = MINIMAP_SIZE_Y / 2 - data->player->pos[Y] * TILE_SIZE;
	put_minimap_tiles(data, win, start);
	put_centered_player(win, data->rgb[PLAYER]);
}

void	dp_centered(t_data *data, t_window *win, int diff[2])
{
	int	start[2];

	start[X] = (WIDTH - MINIMAP_SIZE_X) + ((diff[X] / 2)
			- data->map.extremities_x[BEGIN] * TILE_SIZE - 10);
	start[Y] = diff[Y] / 2 - data->map.extremities_y[BEGIN] * TILE_SIZE - 10;
	put_minimap_tiles(data, win, start);
	put_moving_player(data, win, start);
}
