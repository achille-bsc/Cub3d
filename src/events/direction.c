/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:42:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 22:57:46 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turning_cam(t_player *player, t_movement move)
{
	if (move.dir_left)
	{
		player->dir -= ROT_SPEED;
		if (player->dir < 0)
			player->dir += 2 * M_PI;
	}
	if (move.dir_right)
	{
		player->dir += ROT_SPEED;
		if (player->dir > 2 * M_PI)
			player->dir -= 2 * M_PI;
	}
}
