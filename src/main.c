/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:29 by abosc             #+#    #+#             */
/*   Updated: 2025/08/25 23:04:30 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool	data_init(t_data *data)
// {
// 	ft_bzero(data, sizeof(t_data));
// 	data->map = ft_calloc(sizeof(t_map));
// 	if (!data->map)
// 		return (false);
// 	data->win = ft_calloc(sizeof(t_window));
// 	if (!data->win)
// 		return (false);
// 	data->player = ft_calloc(sizeof(t_player));
// 	if (!data->player)
// 		return (false);
// 	return (true);
// }

static char	**map_maker(char *map_path)
{
	char	*buffer;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("no\n"), NULL);
	buffer = get_all_file(fd);
	return (ft_split(buffer, '\n'));
}

static bool	_mlx_init(t_data *data)
{
	data->win.mlx = mlx_init();
	if (!data->win.mlx)
		return (printf(MLXINIT), false);
	data->win.window = mlx_new_window(data->win.mlx, WIDTH, HEIGHT, NAME);
	if (!data->win.window)
		return (printf(IMGINIT), false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf(ARGS), 1);
	data = ft_calloc(sizeof(t_data));
	if (!data)
		return (1);
	data->map.map = map_maker(argv[1]);
	if (!data->map.map)
		return (1);
	// if (!data_init(data))
	// 	return (1);
	/* TODO: PASING */
	if (!_mlx_init(data))
		return (1);
	/* TODO: KEYMAP INIT */
	// raycaster(data);
	display(data);
	mlx_loop(data->win.mlx);
	return (0);
}