/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:43 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 04:35:18 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ifs(t_data *data, t_window win, char tile, int x, int y)
{
	if (tile == '0')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[0]->texture,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[1]->texture,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == ' ')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[2]->texture,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	player_put(t_data *data)
{
	int	i;
	int	j;

	i = -2;
	while (i < 2)
	{
		j = -2;
		while (j < 2)
			mlx_pixel_put(data->win.mlx, data->win.window, data->player->pos[X]
				* TILE_SIZE + i, data->player->pos[Y]
				* TILE_SIZE + j++, data->rgb[PLAYER]);
		i++;
	}
}

void	minimap_handling(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
			ifs(data, data->win, data->map.map[y][x], x, y);
	}
	x = 0;
	while (data->mini_texture[x])
		mlx_destroy_image(data->win.mlx, data->mini_texture[x++]);
	player_put(data);
}
