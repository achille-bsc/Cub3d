/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_put_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:55:34 by abosc             #+#    #+#             */
/*   Updated: 2025/09/14 20:46:34 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*get_texture(t_data *data, t_img_orientation orientation,
	t_camera *cam, char **map)
{
	if (map[cam->map_y][cam->map_x] == '1' && orientation == NO)
		return (data->texture[NO]);
	else if (map[cam->map_y][cam->map_x] == '1' && orientation == SO)
		return (data->texture[SO]);
	else if (map[cam->map_y][cam->map_x] == '1' && orientation == EA)
		return (data->texture[EA]);
	else if (map[cam->map_y][cam->map_x] == '1' && orientation == WE)
		return (data->texture[WE]);
	else if (map[cam->map_y][cam->map_x] == 'C')
		return (data->door_textures[D_CLOSED]);
	else if (map[cam->map_y][cam->map_x] == 'O')
		return (data->door_textures[D_OPEN]);
	else if (map[cam->map_y][cam->map_x] == 'Q'
		|| map[cam->map_y][cam->map_x] == 'r')
		return (data->door_textures[D_5]);
	else if (map[cam->map_y][cam->map_x] == 'W'
		|| map[cam->map_y][cam->map_x] == 'e')
		return (data->door_textures[D_4]);
	else if (map[cam->map_y][cam->map_x] == 'E'
		|| map[cam->map_y][cam->map_x] == 'w')
		return (data->door_textures[D_3]);
	else
		return (data->door_textures[D_2]);
}

void	put_image_1(t_data *data, t_rendering *rendering, t_camera *cam,
	t_img_orientation orientation)
{
	t_texture	*texture;
	int			y;

	y = rendering->draw[BEGIN];
	rendering->tex_x = TEXTURE_SIZE - rendering->tex_x - 1;
	rendering->step = 1.0 * TEXTURE_SIZE / rendering->line_height;
	rendering->tex_pos = (rendering->draw[BEGIN] - HEIGHT / 2
			+ rendering->line_height / 2) * rendering->step;
	texture = get_texture(data, orientation, cam, data->map.map);
	while (y <= rendering->draw[END])
	{
		rendering->tex_y = (int)rendering->tex_pos;
		if (!texture || !texture->addr)
			(ft_printf(_TEXT_ADDR), exit_w_code(1, data));
		my_mlx_pixel_put(data->win, data->vars->x, y,
			get_color_from_texture(texture, rendering->tex_x,
				rendering->tex_y));
		rendering->tex_pos += rendering->step;
		y++;
	}
}

void	put_image_2(t_data *data, t_rendering *rendering, t_camera *cam,
	t_img_orientation orientation)
{
	t_texture	*texture;
	int			y;

	y = rendering->draw[BEGIN];
	rendering->step = 1.0 * TEXTURE_SIZE / rendering->line_height;
	rendering->tex_pos = (rendering->draw[BEGIN] - HEIGHT / 2
			+ rendering->line_height / 2) * rendering->step;
	texture = get_texture(data, orientation, cam, data->map.map);
	while (y <= rendering->draw[END])
	{
		rendering->tex_y = (int)rendering->tex_pos;
		if (!texture || !texture->addr)
			(ft_printf(_TEXT_ADDR), exit_w_code(1, data));
		my_mlx_pixel_put(data->win, data->vars->x, y,
			get_color_from_texture(texture,
				rendering->tex_x, rendering->tex_y));
		rendering->tex_pos += rendering->step;
		y++;
	}
}

void	select_texture(t_data *data, t_camera *cam,
	t_rendering *rendering)
{
	if (cam->side == 1)
	{
		if (cam->step_y >= 0)
			put_image_1(data, rendering, cam, SO);
		else
			put_image_2(data, rendering, cam, NO);
	}
	else
	{
		if (cam->step_x >= 0)
			put_image_2(data, rendering, cam, EA);
		else
			put_image_1(data, rendering, cam, WE);
	}
}
