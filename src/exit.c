/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:45 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 16:14:45 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_pars_info(t_data *data)
{
	if (data->colors[CEILING])
		free(data->colors[CEILING]);
	if (data->colors[FLOOR])
		free(data->colors[FLOOR]);
	if (data->text[NO])
		free(data->text[NO]);
	if (data->text[SO])
		free(data->text[SO]);
	if (data->text[WE])
		free(data->text[WE]);
	if (data->text[EA])
		free(data->text[EA]);
}

static void	free_textures_2(t_data *data)
{
	if (data->door_textures[D_CLOSED])
	{
		mlx_destroy_image(data->win->mlx,
			data->door_textures[D_CLOSED]->texture);
		ft_freeall("%m", &data->door_textures[D_CLOSED]);
	}
	if (data->door_textures[D_OPEN])
	{
		mlx_destroy_image(data->win->mlx, data->door_textures[D_OPEN]->texture);
		ft_freeall("%m", &data->door_textures[D_OPEN]);
	}
	if (data->door_textures[D_2])
	{
		mlx_destroy_image(data->win->mlx,
			data->door_textures[D_2]->texture);
		ft_freeall("%m", &data->door_textures[D_2]);
	}
	if (data->door_textures[D_3])
	{
		mlx_destroy_image(data->win->mlx, data->door_textures[D_3]->texture);
		ft_freeall("%m", &data->door_textures[D_3]);
	}
}

static void	free_textures(t_data *data)
{
	if (data->texture[NO])
	{
		mlx_destroy_image(data->win->mlx, data->texture[NO]->texture);
		ft_freeall("%m", &data->texture[NO]);
	}
	if (data->texture[SO])
	{
		mlx_destroy_image(data->win->mlx, data->texture[SO]->texture);
		ft_freeall("%m", &data->texture[SO]);
	}
	if (data->texture[EA])
	{
		mlx_destroy_image(data->win->mlx, data->texture[EA]->texture);
		ft_freeall("%m", &data->texture[EA]);
	}
	if (data->texture[WE])
	{
		mlx_destroy_image(data->win->mlx, data->texture[WE]->texture);
		ft_freeall("%m", &data->texture[WE]);
	}
	free_textures_2(data);
	free_textures_3(data);
}

static void	free_m_map(t_data *data)
{
	if (data->mini_texture[M_WALL])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_WALL]->texture);
		ft_freeall("%m", &data->mini_texture[M_WALL]);
	}
	if (data->mini_texture[M_FLOOR])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_FLOOR]->texture);
		ft_freeall("%m", &data->mini_texture[M_FLOOR]);
	}
	if (data->mini_texture[M_OUT])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_OUT]->texture);
		ft_freeall("%m", &data->mini_texture[M_OUT]);
	}
	if (data->mini_texture[M_CLOSE])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_CLOSE]->texture);
		ft_freeall("%m", &data->mini_texture[M_CLOSE]);
	}
	if (data->mini_texture[M_OPEN])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_OPEN]->texture);
		ft_freeall("%m", &data->mini_texture[M_OPEN]);
	}
}

void	exit_w_code(int code, t_data *data)
{
	free_pars_info(data);
	ft_freeall("%d%d%m%m%m%m%m", &data->map.map, &data->map.dummy,
		&data->player, &data->bck_color, &data->cam, &data->w_rendering,
		&data->vars);
	free_textures(data);
	free_m_map(data);
	free_render(data->d_rendering);
	free_door(data->door);
	if (data->win->window)
		mlx_destroy_window(data->win->mlx, data->win->window);
	if (data->win->mlx)
	{
		mlx_mouse_show(data->win->mlx, data->win->window);
		mlx_loop_end(data->win->mlx);
		mlx_destroy_display(data->win->mlx);
		free(data->win->mlx);
	}
	ft_freeall("%m%m", &data->win, &data);
	exit(code);
}
