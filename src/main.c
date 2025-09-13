/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:29 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 16:58:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_colors	*init_bckcolor(t_data *data, unsigned int argb)
{
	t_colors	*colors;

	colors = ft_calloc(sizeof(t_colors));
	if (!colors)
		exit_w_code(1, data);
	colors->alpha = (argb >> 24) & 0xFF;
	colors->r = (argb >> 16) & 0xFF;
	colors->g = (argb >> 8) & 0xFF;
	colors->b = argb & 0xFF;
	return (colors);
}

static bool	_mlx_init(t_data *data)
{
	data->win->mlx = mlx_init();
	if (!data->win->mlx)
		return (exit_w_code(1, data), ft_printf(_MLXINIT), false);
	data->win->window = mlx_new_window(data->win->mlx, WIDTH, HEIGHT, NAME);
	if (!data->win->window)
		return (exit_w_code(1, data), printf(_WININIT), false);
	mlx_mouse_hide(data->win->mlx, data->win->window);
	get_wall_texture(data);
	get_minimap_texture(data);
	mlx_mouse_move(data->win->mlx, data->win->window, WIDTH / 2, HEIGHT / 2);
	return (true);
}

static int	game_loop(t_data *data)
{
	static size_t	fps_counter = 0;
	static double	fps_oldtime = 0;
	double			ms_frame;
	double			fps_newtime;

	ms_frame = 1000 / FPS_MAX;
	data->time = get_time();
	fps_newtime = data->time;
	if (ms_frame <= data->time - data->old_time)
	{
		if (++fps_counter % 2)
			change_door_status(&data->map);
		data->old_time = data->time;
		calculate_plane(data, data->player);
		player_move(data->win, data->map, data->player, data->move);
		display(data);
	}
	if (ONE_SEC <= fps_newtime - fps_oldtime)
	{
		fps_oldtime = fps_newtime;
		data->fps_counter = fps_counter;
		fps_counter = 0;
	}
	usleep(200);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf(_ARGS), 1);
	data = ft_calloc(sizeof(t_data));
	if (!data)
		return (1);
	if (!calloc_init(data))
		return (1);
	data->bck_color = init_bckcolor(data, 0x80525252);
	if (!parser(data, argv[1]))
		return (1);
	data->player->mouse_last_pos = WIDTH / 2;
	if (!_mlx_init(data))
		return (1);
	events(data);
	mlx_loop_hook(data->win->mlx, *game_loop, data);
	mlx_loop(data->win->mlx);
	return (0);
}
