/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 05:41:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 05:55:12 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	to_deg(double rad)
{
	return (rad * 180 / M_PI);
}

double	to_rad(double deg)
{
	return (deg * M_PI / 180);
}

void	calculate_plane(t_data *data, t_player *player)
{
	player->plane[X] = -player->vec[Y] * data->win.fov_factor;
	player->plane[Y] = player->vec[X] * data->win.fov_factor;
}
