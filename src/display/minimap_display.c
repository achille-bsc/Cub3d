/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:55:30 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/12 06:22:59 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ifs(t_data *data, int start[2], int x, int y)
{
	if (data->map.map[y][x] == '0')
		put_tile(data->mini_texture[M_FLOOR], data->win,
			start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
	else if (data->map.map[y][x] == '1')
		put_tile(data->mini_texture[M_WALL], data->win,
			start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
	else if (data->map.map[y][x] == 'O')
		put_tile(data->mini_texture[M_OPEN], data->win,
			start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
	else if (data->map.map[y][x] == 'C')
		put_tile(data->mini_texture[M_CLOSE], data->win,
			start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
	else if (is_voided_door(data->map.map[y][x]))
		put_tile(data->mini_texture[M_CHANGE], data->win,
			start[X] + x * TILE_SIZE, start[Y] + y * TILE_SIZE);
}

static void	put_minimap_tiles(t_data *data, int start[2])
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			ifs(data, start, x, y);
			x++;
		}
		y++;
	}
}

void	dp_full_offset(t_data *data, t_window *win)
{
	int	start[2];

	start[X] = WIDTH - MINIMAP_SIZE_X + (MINIMAP_SIZE_X / 2)
		- data->player->pos[X] * TILE_SIZE - MINIMAP_START_X;
	start[Y] = MINIMAP_SIZE_Y / 2 - data->player->pos[Y] * TILE_SIZE
		+ MINIMAP_START_Y;
	put_minimap_tiles(data, start);
	put_centered_player(win, data->rgb[PLAYER]);
}

void	dp_centered(t_data *data, t_window *win, int diff[2])
{
	int	start[2];

	start[X] = (WIDTH - MINIMAP_SIZE_X) + (diff[X] / 2)
		- data->map.extremities_x[BEGIN] * TILE_SIZE - 10
		- MINIMAP_START_X;
	start[Y] = diff[Y] / 2 - data->map.extremities_y[BEGIN] * TILE_SIZE - 10
		+ MINIMAP_START_Y;
	put_minimap_tiles(data, start);
	put_moving_player(data, win, start);
}
