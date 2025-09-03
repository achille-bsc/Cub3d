/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:07:06 by abosc             #+#    #+#             */
/*   Updated: 2025/09/03 17:10:09 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	press(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		data->move.forward = true;
	else if (keysym == XK_s || keysym == XK_S)
		data->move.backward = true;
	else if (keysym == XK_a || keysym == XK_A)
		data->move.left = true;
	else if (keysym == XK_d || keysym == XK_D)
		data->move.right = true;
	else if (keysym == XK_Up)
		data->move.dir_up = true;
	else if (keysym == XK_Down)
		data->move.dir_down = true;
	else if (keysym == XK_Left)
		data->move.dir_left = true;
	else if (keysym == XK_Right)
		data->move.dir_right = true;
	else if (keysym == XK_Escape)
		clean_quit(data);
	return (0);
}

static int	release(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		data->move.forward = false;
	else if (keysym == XK_s || keysym == XK_S)
		data->move.backward = false;
	else if (keysym == XK_a || keysym == XK_A)
		data->move.left = false;
	else if (keysym == XK_d || keysym == XK_D)
		data->move.right = false;
	else if (keysym == XK_Up)
		data->move.dir_up = false;
	else if (keysym == XK_Down)
		data->move.dir_down = false;
	else if (keysym == XK_Left)
		data->move.dir_left = false;
	else if (keysym == XK_Right)
		data->move.dir_right = false;
	return (0);
}

void	events(t_data *data)
{
	mlx_hook(data->win.window, KEYPRESS, (1L << 0), *press, data);
	mlx_hook(data->win.window, KEYRELEASE, (1L << 1), *release, data);
	mlx_hook(data->win.window, ESCAPE, (1L << 17), *clean_quit, data);
}
