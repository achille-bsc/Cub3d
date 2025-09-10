/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leane <leane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:42:38 by leane             #+#    #+#             */
/*   Updated: 2025/09/10 21:43:36 by leane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_cam_structs(t_data *data)
{
    data->cam = ft_calloc(sizeof(t_camera));
	if (!data->cam)
		exit_w_code(1, data);
	data->door = ft_calloc(sizeof(t_camera));
	if (!data->door)
		(free(data->cam), exit_w_code(1, data));
	data->w_rendering = ft_calloc(sizeof(t_camera));
	if (!data->w_rendering)
		(free(data->cam), free(data->door), exit_w_code(1, data));
	data->d_rendering = ft_calloc(sizeof(t_camera));
	if (!data->d_rendering)
		(ft_freeall("%m%m%m", &data->cam, &data->door, &data->w_rendering),
			exit_w_code(1, data));
}