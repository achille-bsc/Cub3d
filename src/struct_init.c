/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:51:35 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 11:51:09 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}


static t_rendering	**init_door_render_matrix(void)
{
	t_rendering	**render;
	int			i;

	i = 0;
	render = ft_calloc(sizeof(t_rendering *) * MAX_DOOR);
	if (!render)
		return (NULL);
	while (i < MAX_DOOR)
	{
		render[i] = ft_calloc(sizeof(t_rendering));
		if (!render[i])
			return (free_matrix((void **)render), NULL);
		i++;
	}
	return (render);
}

static t_camera	**init_door_matrix(void)
{
	t_camera	**door;
	int			i;

	i = 0;
	door = ft_calloc(sizeof(t_camera *) * MAX_DOOR);
	if (!door)
		return (NULL);
	while (i < MAX_DOOR)
	{
		door[i] = ft_calloc(sizeof(t_camera));
		if (!door[i])
			return (free_matrix((void **)door), NULL);
		i++;
	}
	return (door);
}

bool	calloc_init(t_data *data)
{
	data->vars = ft_calloc(sizeof(t_vars));
	if (!data->vars)
		return (free(data), false);
	data->win = ft_calloc(sizeof(t_window));
	if (!data->win)
		return (free(data->vars), free(data), false);
	data->player = ft_calloc(sizeof(t_player));
	if (!data->player)
		return (free(data->vars), free(data->win), free(data), false);
	data->cam = ft_calloc(sizeof(t_camera));
	if (!data->cam)
		exit_w_code(1, data);
	data->w_rendering = ft_calloc(sizeof(t_camera));
	if (!data->w_rendering)
		exit_w_code(1, data);
	data->d_rendering = init_door_render_matrix();
	if (!data->d_rendering)
		exit_w_code(1, data);
	data->door = init_door_matrix();
	if (!data->door)
		exit_w_code(1, data);
	return (true);
}
