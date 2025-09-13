/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:52:30 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 12:17:51 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_door(t_camera **door)
{
	int	i;

	i = 0;
	while (i < MAX_DOOR)
		free(door[i++]);
	free(door);
}

void	free_render(t_rendering **render)
{
	int	i;

	i = 0;
	while (i < MAX_DOOR)
		free(render[i++]);
	free(render);
}

void	free_textures_3(t_data *data)
{
	if (data->door_textures[D_4])
	{
		mlx_destroy_image(data->win->mlx,
			data->door_textures[D_4]->texture);
		ft_freeall("%m", &data->door_textures[D_4]);
	}
	if (data->door_textures[D_5])
	{
		mlx_destroy_image(data->win->mlx, data->door_textures[D_5]->texture);
		ft_freeall("%m", &data->door_textures[D_5]);
	}
	if (data->mini_texture[M_CHANGE])
	{
		mlx_destroy_image(data->win->mlx,
			data->mini_texture[M_CHANGE]->texture);
		ft_freeall("%m", &data->mini_texture[M_CHANGE]);
	}
	if (data->door_text)
	{
		mlx_destroy_image(data->win->mlx, data->door_text->texture);
		ft_freeall("%m", &data->door_text);
	}
}
