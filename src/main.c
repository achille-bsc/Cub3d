/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:29 by abosc             #+#    #+#             */
/*   Updated: 2025/09/04 18:06:12 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	_mlx_init(t_data *data)
{
	data->win.mlx = mlx_init();
	if (!data->win.mlx)
		return (printf(_MLXINIT), false);
	data->win.window = mlx_new_window(data->win.mlx, WIDTH, HEIGHT, NAME);
	if (!data->win.window)
		return (printf(_IMGINIT), false);
	return (true);
}

static int	game_loop(t_data *data)
{
	size_t	ms_frame;

	ms_frame = 1000 / FPS_MAX;
	data->time = get_time();
	if (ms_frame <= data->time - data->old_time)
	{
		data->old_time = data->time;
		display(data);
	}
	player_move(data->map, data->player, data->move);
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
	load_texture(data);
	events(data);
	mlx_loop_hook(data->win.mlx, *game_loop, data);
	mlx_loop(data->win.mlx);
	return (0);
}
