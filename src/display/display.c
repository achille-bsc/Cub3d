/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:08 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 09:43:58 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	image_drawing(t_data *data, t_window window, t_player *player)
{
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	if (!window.img)
		return (ft_printf(_IMGINIT), exit_w_code(1, data));
	window.img_ptr = mlx_get_data_addr(window.img, &window.bpp,
			&window.line_length, &window.endian);
	draw_frame(window, player->pos, player, data);
	if (data->move.display_minimap)
		minimap_handling(data, window);
	mlx_put_image_to_window(window.mlx, window.window, window.img, 0, 0);
	mlx_destroy_image(window.mlx, window.img);
}

bool	display(t_data *data)
{
	image_drawing(data, data->win, data->player);
	if (data->move.debug)
		print_debug_infos(data);
	return (true);
}
