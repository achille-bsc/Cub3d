/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:02:09 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 13:54:28 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_moving_player(t_data *data, t_window win, int start[2])
{
	int	x;
	int	y;

	y = -2;
	while (y < 2)
	{
		x = -2;
		while (x < 2)
		{
			my_minimap_pixel_put(win, start[X] + data->player->pos[X]
				* TILE_SIZE + x, start[Y] + data->player->pos[Y] * TILE_SIZE
				+ y, data->rgb[PLAYER]);
			x++;
		}
		y++;
	}
}

void	put_first_layer(t_data *data, t_window win)
{
	int	xstart;
	int	x;
	int	ystart;
	int	y;

	xstart = WIDTH - MINIMAP_SIZE_X;
	ystart = 0;
	x = 0;
	while (xstart + (x * TILE_SIZE) <= WIDTH - 20)
	{
		y = 0;
		while (ystart + (y * TILE_SIZE) <= MINIMAP_SIZE_Y - 20)
		{
			put_tile(data->mini_texture[M_OUT], win, xstart + (x * TILE_SIZE),
				ystart + (y * TILE_SIZE));
			y++;
		}
		x++;
	}
}

void	put_centered_player(t_window win, int color)
{
	int	xcenter;
	int	x;
	int	ycenter;
	int	y;

	xcenter = WIDTH - (MINIMAP_SIZE_X / 2);
	x = xcenter - 2;
	ycenter = MINIMAP_SIZE_Y / 2 - 2;
	while (x < xcenter + 2)
	{
		y = ycenter - 2;
		while (y < ycenter + 2)
			my_minimap_pixel_put(win, x, y++, color);
		x++;
	}
}

void	minimap_put_borders(t_window win)
{
	int	x;
	int	y;

	y = -1;
	x = WIDTH - MINIMAP_SIZE_X - MINIMAP_BORDER_SIZE;
	while (++y <= MINIMAP_SIZE_Y && x <= WIDTH - MINIMAP_SIZE_X)
	{
		if (y == MINIMAP_SIZE_Y)
		{
			y = 0;
			x++;
		}
		my_mlx_pixel_put(win, x, y, 0x000000);
	}
	y = MINIMAP_SIZE_Y - 1;
	while (x <= WIDTH && y >= MINIMAP_SIZE_Y - MINIMAP_BORDER_SIZE)
	{
		if (x == WIDTH)
		{
			x = WIDTH - MINIMAP_SIZE_X;
			y--;
		}
		my_mlx_pixel_put(win, x, y, 0x000000);
		x++;
	}
}
