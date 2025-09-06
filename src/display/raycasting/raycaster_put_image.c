/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_put_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:55:34 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 18:58:07 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	truc(t_data *data, int values[3], int x, t_img_orientation orientation)
{
	int	y;

	y = values[1];
	data->rendering.texX = (int)(-data->rendering.wallX * TEXTURE_SIZE);
	data->rendering.step = 1.0 * TEXTURE_SIZE / values[0];
	data->rendering.texPos = (values[1] - HEIGHT / 2 + values[0] / 2)
		* data->rendering.step;
	while (y <= values[2])
	{
		data->rendering.texY = (int)data->rendering.texPos & (TEXTURE_SIZE - 1);
		if (!data->texture[orientation] || !data->texture[orientation]->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, x, y,
			get_color_from_texture(data->texture[orientation],
				data->rendering.texX, data->rendering.texY));
		data->rendering.texPos += data->rendering.step;
		y++;
	}
}

void	truc2(t_data *data, int values[3], int x, t_img_orientation orientation)
{
	int	y;

	y = values[1];
	data->rendering.texX = (int)(data->rendering.wallX * TEXTURE_SIZE);
	data->rendering.step = 1.0 * TEXTURE_SIZE / values[0];
	data->rendering.texPos = (values[1] - HEIGHT / 2 + values[0] / 2)
		* data->rendering.step;
	while (y <= values[2])
	{
		data->rendering.texY = (int)data->rendering.texPos & (TEXTURE_SIZE - 1);
		if (!data->texture[orientation] || !data->texture[orientation]->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, x, y,
			get_color_from_texture(data->texture[orientation],
				data->rendering.texX, data->rendering.texY));
		data->rendering.texPos += data->rendering.step;
		y++;
	}
}
