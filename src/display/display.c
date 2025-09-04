/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:08 by abosc             #+#    #+#             */
/*   Updated: 2025/09/04 17:34:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	to_deg(double dir)
{
	return (dir * 180 / M_PI);
}

void	put_score(t_data *data)
{
	char	txt[50];

	sprintf(txt, "l'angle de visuel est : %f", to_deg(data->player->dir));
	mlx_string_put(data->win.mlx, data->win.window, 1500, 20, 0000000000, txt);
}

bool	display(t_data *data)
{
	raycasting(data);
	minimap_handling(data);
	put_score(data);
	return (true);
}
