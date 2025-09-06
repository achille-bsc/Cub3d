/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:43 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 13:36:00 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_tile(t_texture *text, t_window win, int x, int y)
{
	int	xx;
	int	yy;

	yy = 0;
	while (yy < TILE_SIZE)
	{
		xx = 0;
		while (xx < TILE_SIZE)
		{
			my_minimap_pixel_put(win, xx + x, yy + y,
				get_color_from_texture(text, xx, yy));
			xx++;
		}
		yy++;
	}
}

static void	dp_full_offset(t_data *data, t_window win)
{
	put_centered_player(win, data->rgb[PLAYER]);
}

static void	dp_centered(t_data *data, t_window win, int start[2])
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
	put_moving_player(data, win, start);
}

void	put_minimap(t_data *data, t_window win)
{
	int	diff[2];
	int	start[2];

	diff[X] = MINIMAP_SIZE_X - (data->map.size_x * TILE_SIZE);
	start[X] = (WIDTH - MINIMAP_SIZE_X) + ((diff[X] / 2)
			- data->map.extremities_x[BEGIN] * TILE_SIZE - 10);
	diff[Y] = MINIMAP_SIZE_Y - data->map.size_y * TILE_SIZE;
	start[Y] = diff[Y] / 2 - data->map.extremities_y[BEGIN] * TILE_SIZE - 10;
	if (diff[X] < 0 || diff[Y] < 0)
		dp_full_offset(data, win);
	else
		dp_centered(data, win, start);
}

void	minimap_handling(t_data *data, t_window win)
{
	put_first_layer(data, win);
	put_minimap(data, win);
	minimap_put_borders(win);
}
