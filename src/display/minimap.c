/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:43 by abosc             #+#    #+#             */
/*   Updated: 2025/09/04 17:32:53 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	minimap_asset_init(t_data *data, t_window win)
{
	data->mini_texture[0] = xpm_img(win.mlx, "assets/black.xpm", TILE_SIZE);
	if (!data->mini_texture[0])
		return (0);
	data->mini_texture[1] = xpm_img(win.mlx, "assets/cobble.xpm", TILE_SIZE);
	if (!data->mini_texture[1])
		return (1);
	data->mini_texture[2] = xpm_img(win.mlx, "assets/Lava.xpm", TILE_SIZE);
	if (!data->mini_texture[2])
		return (2);
	return (3);
}

static void	ifs(t_data *data, t_window win, char tile, int x, int y)
{
	if (tile == '0')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[0],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[1],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == ' ')
		mlx_put_image_to_window(win.mlx, win.window, data->mini_texture[2],
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
	int	res;

	res = minimap_asset_init(data, data->win);
	if (res != 3)
		(ft_printf(_ASSET_INIT, res), exit_w_code(1, data));
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
