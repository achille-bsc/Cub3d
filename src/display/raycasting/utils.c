/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:42:38 by leane             #+#    #+#             */
/*   Updated: 2025/09/12 06:18:37 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cam_structs(t_data *data)
{
	data->cam = ft_calloc(sizeof(t_camera));
	if (!data->cam)
		exit_w_code(1, data);
	data->w_rendering = ft_calloc(sizeof(t_camera));
	if (!data->w_rendering)
		(free(data->cam), exit_w_code(1, data));
}

bool	is_voided_door(char c)
{
	if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 'Q' || c == 'W'
		|| c == 'E' || c == 'R' || c == 'O')
		return (true);
	return (false);
}
