/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:29 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 04:29:29 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving(t_movement move, t_player *player)
{
	if (move.backward || move.forward || move.left || move.right
		|| move.dir_up || move.dir_down || move.dir_left || move.dir_right)
	{
		player->vec[X] = cos(player->dir);
		player->vec[Y] = sin(player->dir);
	}
}

static bool	_mlx_init(t_data *data)
{
	data->win.mlx = mlx_init();
	if (!data->win.mlx)
		return (printf(_MLXINIT), false);
	data->win.window = mlx_new_window(data->win.mlx, WIDTH, HEIGHT, NAME);
	if (!data->win.window)
		return (printf(_WININIT), false);
	get_wall_texture(data);
	get_minimap_texture(data);
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
		fps_counter++;
		data->old_time = data->time;
		moving(data->move, data->player);
		player_move(data->map, data->player, data->move);
		display(data);
	}
	if (ONE_SEC <= fps_newtime - fps_oldtime)
	{
		fps_oldtime = fps_newtime;
		data->fps_counter = fps_counter;
		fps_counter = 0;
	}
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
	if (!parser(data, argv[1]))
		return (1);
	if (!_mlx_init(data))
		return (1);
	events(data);
	mlx_loop_hook(data->win.mlx, *game_loop, data);
	mlx_loop(data->win.mlx);
	return (0);
}
