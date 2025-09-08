/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_put_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:55:34 by abosc             #+#    #+#             */
/*   Updated: 2025/09/08 14:04:37 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	truc(t_data *data, int values[3], int x, t_img_orientation orientation)
{
	int	y;

	y = values[1];
	data->rendering.tex_x = (int)(-data->rendering.wall_x * TEXTURE_SIZE);
	data->rendering.step = 1.0 * TEXTURE_SIZE / values[0];
	data->rendering.tex_pos = (values[1] - HEIGHT / 2 + values[0] / 2)
		* data->rendering.step;
	while (y <= values[2])
	{
		data->rendering.tex_y = (int)data->rendering.tex_pos
			& (TEXTURE_SIZE - 1);
		if (!data->texture[orientation] || !data->texture[orientation]->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, x, y,
			get_color_from_texture(data->texture[orientation],
				data->rendering.tex_x, data->rendering.tex_y));
		data->rendering.tex_pos += data->rendering.step;
		y++;
	}
}

void	truc2(t_data *data, int values[3], int x, t_img_orientation orientation)
{
	int	y;

	y = values[1];
	data->rendering.tex_x = (int)(data->rendering.wall_x * TEXTURE_SIZE);
	data->rendering.step = 1.0 * TEXTURE_SIZE / values[0];
	data->rendering.tex_pos = (values[1] - HEIGHT / 2 + values[0] / 2)
		* data->rendering.step;
	while (y <= values[2])
	{
		data->rendering.tex_y = (int)data->rendering.tex_pos
			& (TEXTURE_SIZE - 1);
		if (!data->texture[orientation] || !data->texture[orientation]->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, x, y,
			get_color_from_texture(data->texture[orientation],
				data->rendering.tex_x, data->rendering.tex_y));
		data->rendering.tex_pos += data->rendering.step;
		y++;
	}
}
