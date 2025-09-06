/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:07:06 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 15:12:31 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	press(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		data->move.forward = true;
	if (keysym == XK_s || keysym == XK_S)
		data->move.backward = true;
	if (keysym == XK_a || keysym == XK_A)
		data->move.left = true;
	if (keysym == XK_d || keysym == XK_D)
		data->move.right = true;
	if (keysym == XK_Up)
		data->move.dir_up = true;
	if (keysym == XK_Down)
		data->move.dir_down = true;
	if (keysym == XK_Left)
		data->move.dir_left = true;
	if (keysym == XK_Right)
		data->move.dir_right = true;
	if (keysym == XK_Shift_L)
		data->move.sprint = true;
	if (keysym == XK_Escape)
		clean_quit(data);
	if (keysym == XK_z || keysym == XK_Z)
		respawn(data);
	if (keysym == XK_c || keysym == XK_C)
		re_center_cam(data);
	return (0);
}

static int	release(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		data->move.forward = false;
	if (keysym == XK_s || keysym == XK_S)
		data->move.backward = false;
	if (keysym == XK_a || keysym == XK_A)
		data->move.left = false;
	if (keysym == XK_d || keysym == XK_D)
		data->move.right = false;
	if (keysym == XK_Up)
		data->move.dir_up = false;
	if (keysym == XK_Down)
		data->move.dir_down = false;
	if (keysym == XK_Left)
		data->move.dir_left = false;
	if (keysym == XK_Right)
		data->move.dir_right = false;
	if (keysym == XK_Shift_L)
		data->move.sprint = false;
	if (keysym == XK_e || keysym == XK_E)
		debug_info(data);
	if (keysym == XK_m || keysym == XK_M)
		minimap_display(data);
	return (0);
}

void	events(t_data *data)
{
	mlx_hook(data->win.window, KEYPRESS, (1L << 0), *press, data);
	mlx_hook(data->win.window, KEYRELEASE, (1L << 1), *release, data);
	mlx_hook(data->win.window, ESCAPE, (1L << 17), *clean_quit, data);
}
