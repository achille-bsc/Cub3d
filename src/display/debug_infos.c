/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 05:37:28 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 17:50:29 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	get_orientation(double dir)
{
	double	deg_dir;

	deg_dir = to_deg(dir);
	if (deg_dir >= 45 && deg_dir < 135)
		return ('S');
	else if (deg_dir >= 135 && deg_dir < 225)
		return ('W');
	else if (deg_dir >= 225 && deg_dir < 315)
		return ('N');
	else
		return ('E');
}

static void	put_debug_info(t_data *data)
{
	char	*txt;

	txt = NULL;
	ft_smprintf(&txt, "pos {X;Y} : {%f;%f}", data->player->pos[X],
		data->player->pos[Y]);
	mlx_string_put(data->win->mlx, data->win->window, 700, 20, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "fps : %u", data->fps_counter);
	mlx_string_put(data->win->mlx, data->win->window, 700, 40, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "orientation : %c", get_orientation(data->player->dir));
	mlx_string_put(data->win->mlx, data->win->window, 700, 60, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "angle (deg) : %f", to_deg(data->player->dir));
	mlx_string_put(data->win->mlx, data->win->window, 500, 20, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "angle (rad) : %f", data->player->dir);
	mlx_string_put(data->win->mlx, data->win->window, 500, 40, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "vecteur X : %f", data->player->vec[X]);
	mlx_string_put(data->win->mlx, data->win->window, 500, 60, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "vecteur Y : %f", data->player->vec[Y]);
	mlx_string_put(data->win->mlx, data->win->window, 500, 80, 0000000000, txt);
	ft_str_reset(&txt);
}

static void	put_debug_info_2(t_data *data)
{
	char	*txt;

	txt = NULL;
	txt = ft_strjoin("North texture : ", data->text[NO]);
	mlx_string_put(data->win->mlx, data->win->window, 200, 20, 0000000000, txt);
	ft_str_reset(&txt);
	txt = ft_strjoin("South texture : ", data->text[SO]);
	mlx_string_put(data->win->mlx, data->win->window, 200, 40, 0000000000, txt);
	ft_str_reset(&txt);
	txt = ft_strjoin("West texture  : ", data->text[WE]);
	mlx_string_put(data->win->mlx, data->win->window, 200, 60, 0000000000, txt);
	ft_str_reset(&txt);
	txt = ft_strjoin("East texture  : ", data->text[EA]);
	mlx_string_put(data->win->mlx, data->win->window, 200, 80, 0000000000, txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "PlaneX : %f", data->player->plane[X]);
	mlx_string_put(data->win->mlx, data->win->window, 500, 100, 0000000000,
		txt);
	ft_str_reset(&txt);
	ft_smprintf(&txt, "PlaneY : %f", data->player->plane[Y]);
	mlx_string_put(data->win->mlx, data->win->window, 500, 120, 0000000000,
		txt);
	ft_str_reset(&txt);
}

void	print_debug_infos(t_data *data)
{
	put_debug_info(data);
	put_debug_info_2(data);
}
