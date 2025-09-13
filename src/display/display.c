/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:08 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 06:42:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_text_background(t_data *data)
{
	int	x;
	int	y;

	y = HEIGHT - DOOR_TEXT_Y_START - DOOR_BCKGRND_START;
	while (y < HEIGHT - DOOR_TEXT_Y_START + DOOR_TEXT_HEIGHT
		+ DOOR_BCKGRND_START)
	{
		x = WIDTH / 2 - DOOR_TEXT_WIDTH / 2 - DOOR_BCKGRND_START;
		while (x < WIDTH / 2 - DOOR_TEXT_WIDTH / 2 + DOOR_TEXT_WIDTH
			+ DOOR_BCKGRND_START)
		{
			pixel_put_transparency(data, x, y);
			x++;
		}
		y++;
	}
}

static void	display_door_msg(t_data *data, t_window *win)
{
	int	x;
	int	y;
	int	xx;
	int	yy;

	display_text_background(data);
	x = WIDTH / 2 - DOOR_TEXT_WIDTH / 2;
	y = HEIGHT - DOOR_TEXT_Y_START;
	yy = 0;
	while (yy < DOOR_TEXT_HEIGHT)
	{
		xx = 0;
		while (xx < DOOR_TEXT_WIDTH)
		{
			my_mlx_pixel_put(win, x + xx, y + yy,
				get_color_from_texture(data->door_text, xx, yy));
			xx++;
		}
		yy++;
	}
}

static void	check_for_doors(t_data *data, t_map map, double pos[2])
{
	if (map.map[(int)pos[Y]][(int)(pos[X] + 0.80)] == 'C')
		display_door_msg(data, data->win);
	else if (map.map[(int)pos[Y]][(int)(pos[X] - 0.80)] == 'C')
		display_door_msg(data, data->win);
	else if (map.map[(int)(pos[Y] + 0.80)][(int)pos[X]] == 'C')
		display_door_msg(data, data->win);
	else if (map.map[(int)(pos[Y] - 0.80)][(int)pos[X]] == 'C')
		display_door_msg(data, data->win);
}

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
	check_for_doors(data, data->map, player->pos);
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
