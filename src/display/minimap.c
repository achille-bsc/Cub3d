/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:43 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 14:23:12 by lvan-bre         ###   ########.fr       */
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

void	minimap_handling(t_data *data, t_window win)
{
	int	diff[2];

	put_first_layer(data, win);
	diff[X] = MINIMAP_SIZE_X - (data->map.size_x * TILE_SIZE);
	diff[Y] = MINIMAP_SIZE_Y - data->map.size_y * TILE_SIZE;
	if (diff[X] < 0 || diff[Y] < 0)
		dp_full_offset(data, win);
	else
		dp_centered(data, win, diff);
	minimap_put_borders(win);
}
