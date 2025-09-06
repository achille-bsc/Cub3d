/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:04:45 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 19:28:02 by abosc            ###   ########.fr       */
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

static void	free_textures(t_data *data)
{
	if (data->texture[NO])
	{
		mlx_destroy_image(data->win->mlx, data->texture[NO]->texture);
		ft_freeall("%m%m", data->texture[NO]);
	}
	if (data->texture[SO])
	{
		mlx_destroy_image(data->win->mlx, data->texture[SO]->texture);
		ft_freeall("%m%m", data->texture[SO]);
	}
	if (data->texture[EA])
	{
		mlx_destroy_image(data->win->mlx, data->texture[EA]->texture);
		ft_freeall("%m%m", data->texture[EA]);
	}
	if (data->texture[WE])
	{
		mlx_destroy_image(data->win->mlx, data->texture[WE]->texture);
		ft_freeall("%m%m", data->texture[WE]);
	}
}

static void	free_m_map(t_data *data)
{
	if (data->mini_texture[M_WALL])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_WALL]->texture);
		ft_freeall("%m%m", data->mini_texture[M_WALL]);
	}
	if (data->mini_texture[M_FLOOR])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_FLOOR]->texture);
		ft_freeall("%m%m", data->mini_texture[M_FLOOR]);
	}
	if (data->mini_texture[M_OUT])
	{
		mlx_destroy_image(data->win->mlx, data->mini_texture[M_OUT]->texture);
		ft_freeall("%m%m", data->mini_texture[M_OUT]);
	}
}

void	exit_w_code(int code, t_data *data)
{
	free_pars_info(data);
	ft_freeall("%d%d%m", &data->map.map, &data->map.dummy, &data->player);
	free_textures(data);
	free_m_map(data);
	if (data->win->window)
		mlx_destroy_window(data->win->mlx, data->win->window);
	if (data->win->mlx)
	{
		mlx_loop_end(data->win->mlx);
		mlx_destroy_display(data->win->mlx);
		free(data->win->mlx);
	}
	ft_freeall("%m%m", &data->win, &data);
	exit(code);
}

int	clean_quit(t_data *data)
{
	exit_w_code(0, data);
	return (0);
}
