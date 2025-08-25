/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:45 by abosc             #+#    #+#             */
/*   Updated: 2025/08/25 23:04:50 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_freeall("%m", data);
	exit(code);
}