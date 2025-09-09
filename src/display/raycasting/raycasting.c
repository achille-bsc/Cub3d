/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:53:23 by abosc             #+#    #+#             */
/*   Updated: 2025/09/09 16:45:30 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rendering(t_data *data, t_camera *cam,
	t_pixel_rendering *rendering, int side)
{
	if (side == 0)
		rendering->perp_wall_dist = (cam->map_x - data->player->pos[X]
				+ (1 - cam->step_x) / 2) / cam->ray_dir_x;
	else
		rendering->perp_wall_dist = (cam->map_y - data->player->pos[Y]
				+ (1 - cam->step_y) / 2) / cam->ray_dir_y;
	if (side == 0)
		rendering->perp_wall_dist = cam->side_dist_x - cam->delta_dist_x;
	else
		rendering->perp_wall_dist = cam->side_dist_y - cam->delta_dist_y;
}

static void	draw_background(t_data *data, int x)
{
	int	y;
	int	floor_line_height;

	data->vars->line_height = (int)(HEIGHT / data->w_rendering->perp_wall_dist);
	data->vars->draw[0] = -data->vars->line_height / 2 + HEIGHT / 2;
	if (data->vars->draw[0] < 0)
		data->vars->draw[0] = 0;
	data->vars->draw[1] = data->vars->line_height / 2 + HEIGHT / 2;
	if (data->vars->draw[1] >= HEIGHT)
		data->vars->draw[1] = HEIGHT - 1;
	y = 0;
	while (y < data->vars->draw[0])
		my_mlx_pixel_put(data->win, x, y++, data->rgb[CEILING]);
	floor_line_height = data->vars->draw[1] + 1;
	while (floor_line_height < HEIGHT)
		my_mlx_pixel_put(data->win, x, floor_line_height++, data->rgb[FLOOR]);
}

static void	init_pixel_art(t_data *data, t_camera *cam,
	t_pixel_rendering *rendering, int side)
{
	if (side == 0)
		rendering->wall_x = data->player->pos[Y]
			+ rendering->perp_wall_dist * cam->ray_dir_y;
	else
		rendering->wall_x = data->player->pos[X]
			+ rendering->perp_wall_dist * cam->ray_dir_x;
	rendering->wall_x -= floor(rendering->wall_x);
}

void	pixels_rendering(t_data *data, t_camera *cam, int side, int x)
{
	init_rendering(data, cam, data->w_rendering, side);
	init_rendering(data, data->door, data->d_rendering, side);
	draw_background(data, x);
	init_pixel_art(data, cam, data->w_rendering, side);
	init_pixel_art(data, cam, data->d_rendering, side);
	data->vars->x = x;
	select_texture(data, cam, data->vars);
	select_texture(data, data->door, data->vars);
}

void	draw_frame(t_player *player, t_data *data)
{
	int			x;

	data->cam = ft_calloc(sizeof(t_camera));
	if (!data->cam)
		exit_w_code(1, data);
	data->door = ft_calloc(sizeof(t_camera));
	if (!data->door)
		(free(data->cam), exit_w_code(1, data));
	data->w_rendering = ft_calloc(sizeof(t_camera));
	if (!data->w_rendering)
		(free(data->cam), free(data->door), exit_w_code(1, data));
	data->d_rendering = ft_calloc(sizeof(t_camera));
	if (!data->d_rendering)
		(ft_freeall("%m%m%m", &data->cam, &data->door, &data->w_rendering),
			exit_w_code(1, data));
	x = -1;
	while (++x < WIDTH)
	{
		cam_val_setter(player, data->cam, x);
		rays_dir_setter(data->cam, player->pos);
		pixels_rendering(data, data->cam, rays_calculator(data->cam, data), x);
		ft_bzero(data->cam, sizeof(t_camera));
		ft_bzero(data->door, sizeof(t_camera));
	}
	ft_freeall("%m%m%m%m", &data->cam, &data->door, &data->w_rendering,
		&data->d_rendering);
}
