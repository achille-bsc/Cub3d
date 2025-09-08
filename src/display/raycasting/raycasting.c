/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:53:23 by abosc             #+#    #+#             */
/*   Updated: 2025/09/08 13:56:53 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rendering(t_data *data, t_camera *cam, int side)
{
	if (side == 0)
		data->rendering.perp_wall_dist = (cam->map_x - data->player->pos[X] + (1
					- cam->step_x) / 2) / cam->ray_dir_x;
	else
		data->rendering.perp_wall_dist = (cam->map_y - data->player->pos[Y] + (1
					- cam->step_y) / 2) / cam->ray_dir_y;
	if (side == 0)
		data->rendering.perp_wall_dist = cam->side_dist_x - cam->delta_dist_x;
	else
		data->rendering.perp_wall_dist = cam->side_dist_y - cam->delta_dist_y;
}

static int	*truc_machin(t_data *data, int *line_height, int x)
{
	int	*draw;
	int	y;

	draw = ft_calloc(sizeof(int) * 2);
	*line_height = (int)(HEIGHT / data->rendering.perp_wall_dist);
	draw[0] = -*line_height / 2 + HEIGHT / 2;
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = *line_height / 2 + HEIGHT / 2;
	if (draw[1] >= HEIGHT)
		draw[1] = HEIGHT - 1;
	y = 0;
	while (y < draw[0])
		my_mlx_pixel_put(data->win, x, y++, 0x87CEEB);
	return (draw);
}

static void	init_pixel_art(t_data *data, t_camera *cam, int side)
{
	if (side == 0)
		data->rendering.wall_x = data->player->pos[Y]
			+ data->rendering.perp_wall_dist * cam->ray_dir_y;
	else
		data->rendering.wall_x = data->player->pos[X]
			+ data->rendering.perp_wall_dist * cam->ray_dir_x;
	data->rendering.wall_x -= floor(data->rendering.wall_x);
}

void	pixels_rendering(t_data *data, t_camera *cam, int side, int x)
{
	int	line_height;
	int	*draw;

	init_rendering(data, cam, side);
	draw = truc_machin(data, &line_height, x);
	init_pixel_art(data, cam, side);
	if (side == 1)
	{
		if (cam->step_y >= 0)
			truc(data, (int [3]){line_height, draw[0], draw[1]}, x, SO);
		else
			truc2(data, (int [3]){line_height, draw[0], draw[1]}, x, NO);
	}
	else
	{
		if (cam->step_x >= 0)
			truc2(data, (int [3]){line_height, draw[0], draw[1]}, x, EA);
		else
			truc(data, (int [3]){line_height, draw[0], draw[1]}, x, WE);
	}
	line_height = draw[1] + 1;
	while (line_height < HEIGHT)
		my_mlx_pixel_put(data->win, x, line_height++, 0x444444);
	ft_mem_reset((void *)&draw);
}

void	draw_frame(t_player *player, t_data *data)
{
	int			x;
	t_camera	*cam;

	x = 0;
	cam = ft_calloc(sizeof(t_camera));
	if (!cam)
		exit_w_code(1, data);
	while (x < WIDTH)
	{
		cam_val_setter(player, cam, x);
		rays_dir_setter(cam, player->pos);
		pixels_rendering(data, cam, rays_calculator(cam, data), x);
		ft_bzero(cam, sizeof(t_camera));
		x++;
	}
	free(cam);
}
