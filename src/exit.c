/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:45 by abosc             #+#    #+#             */
/*   Updated: 2025/08/26 18:36:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_w_code(int code, t_data *data)
{
	int	i;

	i = 0;
	while (data->mini_texture[i])
		mlx_destroy_image(data->win.mlx, data->mini_texture[i++]);
	if (data->win.window)
		mlx_destroy_window(data->win.mlx, data->win.window);
	if (data->win.mlx)
	{
		mlx_loop_end(data->win.mlx);
		mlx_destroy_display(data->win.mlx);
		free(data->win.mlx);
	}
	ft_freeall("%d%m", &data->map.map, &data);
	exit(code);
}

int	clean_quit(t_data *data)
{
	exit_w_code(0, data);
	return (0);
}
