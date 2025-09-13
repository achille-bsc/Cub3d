/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:53:23 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 12:23:33 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rendering(t_camera *cam, t_rendering *rendering,
	int side)
{
	if (side == 0)
		rendering->perp_wall_dist = cam->side_dist_x - cam->delta_dist_x;
	else
		rendering->perp_wall_dist = cam->side_dist_y - cam->delta_dist_y;
}

static void	draw_background(t_data *data, t_rendering *render, int x)
{
	int	y;
	int	floor_line_height;

	render->line_height = (int)(HEIGHT / render->perp_wall_dist);
	render->draw[0] = -render->line_height / 2 + HEIGHT / 2;
	if (render->draw[0] < 0)
		render->draw[0] = 0;
	render->draw[1] = render->line_height / 2 + HEIGHT / 2;
	if (render->draw[1] >= HEIGHT)
		render->draw[1] = HEIGHT - 1;
	y = 0;
	while (y < render->draw[0])
		my_mlx_pixel_put(data->win, x, y++, data->rgb[CEILING]);
	floor_line_height = render->draw[1] + 1;
	while (floor_line_height < HEIGHT)
		my_mlx_pixel_put(data->win, x, floor_line_height++, data->rgb[FLOOR]);
}

static void	init_pixel_art(t_data *data, t_camera *cam,
	t_rendering *rendering, int side)
{
	if (side == 0)
		rendering->wall_x = data->player->pos[Y]
			+ rendering->perp_wall_dist * cam->ray_dir_y;
	else
		rendering->wall_x = data->player->pos[X]
			+ rendering->perp_wall_dist * cam->ray_dir_x;
	rendering->wall_x -= floor(rendering->wall_x);
}

void	pixels_rendering(t_data *data, t_camera *cam, t_camera **door, int x)
{
	data->vars->i = -1;
	init_rendering(cam, data->w_rendering, cam->side);
	if (data->nmb_of_doors > 0)
		while (++data->vars->i < data->nmb_of_doors)
			init_rendering(door[data->vars->i],
				data->d_rendering[data->vars->i], door[data->vars->i]->side);
	draw_background(data, data->w_rendering, x);
	data->vars->i = -1;
	if (data->nmb_of_doors > 0)
		while (++data->vars->i < data->nmb_of_doors)
			draw_background(data, data->d_rendering[data->vars->i], x);
	init_pixel_art(data, cam, data->w_rendering, cam->side);
	data->vars->x = x;
	select_texture(data, cam, data->w_rendering);
	data->vars->i = -1;
	if (data->nmb_of_doors > 0)
	{
		while (++data->vars->i < data->nmb_of_doors)
		{
			init_pixel_art(data, door[data->vars->i],
				data->d_rendering[data->vars->i], door[data->vars->i]->side);
			select_texture(data, door[data->vars->i],
				data->d_rendering[data->vars->i]);
		}
	}
}

void	draw_frame(t_player *player, t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		cam_val_setter(player, data->cam, x);
		rays_dir_setter(data->cam, player->pos);
		data->nmb_of_doors = get_nmb_of_doors(data->cam, data->map.map);
		if (data->nmb_of_doors > MAX_DOOR)
			data->nmb_of_doors = MAX_DOOR;
		rays_dist_calculator(data, data->cam, data->door, data->map.map);
		pixels_rendering(data, data->cam, data->door, x);
		ft_bzero(data->cam, sizeof(t_camera));
		ft_bzero(data->w_rendering, sizeof(t_rendering));
	}
}
