/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:45 by abosc             #+#    #+#             */
/*   Updated: 2025/08/28 21:04:46 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_pars_info(t_data *data)
{
	if (data->colors[CEILING])
		free(data->colors[CEILING]);
	if (data->colors[FLOOR])
		free(data->colors[FLOOR]);
	if (data->text[NO])
		free(data->text[NO]);
	if (data->text[SO])
		free(data->text[SO]);
	if (data->text[WE])
		free(data->text[WE]);
	if (data->text[EA])
		free(data->text[EA]);
}

void	exit_w_code(int code, t_data *data)
{
	if (data->win.window)
		mlx_destroy_window(data->win.mlx, data->win.window);
	if (data->win.mlx)
	{
		mlx_loop_end(data->win.mlx);
		mlx_destroy_display(data->win.mlx);
		free(data->win.mlx);
	}
	free_pars_info(data);
	ft_freeall("%d%m", &data->map.map, &data);
	exit(code);
}

int	clean_quit(t_data *data)
{
	exit_w_code(0, data);
	return (0);
}
