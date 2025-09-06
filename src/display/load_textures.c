/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:21:30 by abosc             #+#    #+#             */
/*   Updated: 2025/09/06 17:35:50 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*load_texture(t_data *data, char *asset_file, int size)
{
	t_texture	*texture;

	texture = ft_calloc(sizeof(t_texture));
	if (!texture)
		exit_w_code(1, data);
	texture->texture = xpm_img(data->win->mlx, asset_file, size);
	if (!texture->texture)
		return (ft_printf(_ASSET_INIT), exit_w_code(1, data), NULL);
	texture->addr = mlx_get_data_addr(texture->texture,
			&(texture->bpp), &(texture->size_line),
			&(texture->endian));
	if (!texture->addr)
		return (ft_printf(_GET_ADDR), exit_w_code(1, data), NULL);
	return (texture);
}

void	get_minimap_texture(t_data *data)
{
	data->mini_texture[M_FLOOR] = load_texture(data, FLOOR_TEXTURE, TILE_SIZE);
	data->mini_texture[M_WALL] = load_texture(data, WALL_TEXTURE, TILE_SIZE);
	data->mini_texture[M_OUT] = load_texture(data, OUT_TEXTURE, TILE_SIZE);
}

void	get_wall_texture(t_data *data)
{
	data->texture[NO] = load_texture(data, data->text[NO], TEXTURE_SIZE);
	data->texture[SO] = load_texture(data, data->text[SO], TEXTURE_SIZE);
	data->texture[WE] = load_texture(data, data->text[WE], TEXTURE_SIZE);
	data->texture[EA] = load_texture(data, data->text[EA], TEXTURE_SIZE);
}
