/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_put_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:55:34 by abosc             #+#    #+#             */
/*   Updated: 2025/09/09 16:47:32 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*get_texture(t_data *data, t_img_orientation orientation,
	t_camera *cam)
{
	if (data->map.map[cam->map_y][cam->map_x] == '1' && orientation == NO)
		return (data->texture[NO]);
	if (data->map.map[cam->map_y][cam->map_x] == '1' && orientation == SO)
		return (data->texture[SO]);
	if (data->map.map[cam->map_y][cam->map_x] == '1' && orientation == EA)
		return (data->texture[EA]);
	if (data->map.map[cam->map_y][cam->map_x] == '1' && orientation == WE)
		return (data->texture[WE]);
	if (data->map.map[cam->map_y][cam->map_x] == 'C')
		return (data->door_textures[CLOSED]);
	if (data->map.map[cam->map_y][cam->map_x] == 'O')
		return (data->door_textures[OPEN]);
	return (NULL);
}

/*	values identification :
	0 : line_height;
	1 : x;
	2 : draw[0];
	3 : draw[1];
*/
void	put_image_1(t_data *data, t_pixel_rendering *rendering, t_vars *vars,
	t_img_orientation orientation)
{
	t_texture	*texture;
	int			y;

	y = vars->draw[0];
	rendering->tex_x = (int)(rendering->wall_x * TEXTURE_SIZE);
	rendering->step = 1.0 * TEXTURE_SIZE / vars->line_height;
	rendering->tex_pos = (vars->draw[0] - HEIGHT / 2 + vars->line_height / 2)
		* rendering->step;
	texture = get_texture(data, orientation, data->cam);
	while (y <= vars->draw[1])
	{
		rendering->tex_y = (int)rendering->tex_pos
			& (TEXTURE_SIZE - 1);
		if (!texture || !texture->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, vars->x, y,
			get_color_from_texture(texture, rendering->tex_x,
				rendering->tex_y));
		rendering->tex_pos += rendering->step;
		y++;
	}
}

void	put_image_2(t_data *data, t_pixel_rendering *rendering, t_vars *vars,
	t_img_orientation orientation)
{
	t_texture	*texture;
	int			y;

	y = vars->draw[0];
	rendering->tex_x = (int)(rendering->wall_x * TEXTURE_SIZE);
	rendering->step = 1.0 * TEXTURE_SIZE / vars->line_height;
	rendering->tex_pos = (vars->draw[0] - HEIGHT / 2 + vars->line_height / 2)
		* rendering->step;
	texture = get_texture(data, orientation, data->cam);
	while (y <= vars->draw[1])
	{
		rendering->tex_y = (int)rendering->tex_pos
			& (TEXTURE_SIZE - 1);
		if (!texture || !texture->addr)
			exit_w_code(1, data);
		my_mlx_pixel_put(data->win, vars->x, y,
			get_color_from_texture(texture,
				rendering->tex_x, rendering->tex_y));
		rendering->tex_pos += rendering->step;
		y++;
	}
}

/*	vars identifications :
	0 : line_height;
	1 : side;
	2 : x;
*/
void	select_texture(t_data *data, t_camera *cam, t_vars *vars)
{
	if (vars->side == 1)
	{
		if (cam->step_y >= 0)
			put_image_1(data, data->w_rendering, vars, SO);
		else
			put_image_2(data, data->w_rendering, vars, NO);
	}
	else
	{
		if (cam->step_x >= 0)
			put_image_2(data, data->w_rendering, vars, EA);
		else
			put_image_1(data, data->w_rendering, vars, WE);
	}
}
