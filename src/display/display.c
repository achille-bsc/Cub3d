/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:08 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 17:41:46 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	image_drawing(t_data *data, t_window *win, t_player *player)
{
	win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (!win->img)
		return (ft_printf(_IMGINIT), exit_w_code(1, data));
	win->img_ptr = mlx_get_data_addr(win->img, &win->bpp,
			&win->line_length, &win->endian);
	draw_frame(player, data);
	if (data->move.display_minimap)
		minimap_handling(data, win);
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
}

bool	display(t_data *data)
{
	image_drawing(data, data->win, data->player);
	if (data->move.debug)
		print_debug_infos(data);
	return (true);
}
