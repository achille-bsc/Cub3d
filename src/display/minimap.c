/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:43 by abosc             #+#    #+#             */
/*   Updated: 2025/08/28 21:03:55 by lvan-bre         ###   ########.fr       */
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

void	minimap_handling(t_data *data)
{
	int	y;
	int	x;
	int	res;

	res = minimap_asset_init(data, data->win);
	if (res != 3)
	{
		ft_printf(_ASSET_INIT, res);
		exit_w_code(1, data);
	}
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			ifs(data, data->win, data->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
	int	a = 0;
	while (data->mini_texture[a])
	{
		mlx_destroy_image(data->win.mlx, data->mini_texture[a]);
		data->mini_texture[a] = NULL;
		a++;
	}

	int	i;
	int	j;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(data->win.mlx, data->win.window, (int)data->player.pos[X] * 20 + i , (int)data->player.pos[Y] * 20 + j, 0255000000);
			j++;
		}
		i++;
	}

}
