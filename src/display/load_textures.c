/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:21:30 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 06:41:15 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*load_door_text(t_data *data, char *asset_file,
	int width, int height)
{
	t_texture	*texture;

	texture = ft_calloc(sizeof(t_texture));
	if (!texture)
		exit_w_code(1, data);
	texture->texture = mlx_xpm_file_to_image(data->win->mlx, asset_file,
			&width, &height);
	if (!texture->texture)
		return (free(texture), ft_printf(_ASSET_INIT), exit_w_code(1, data)
			, NULL);
	texture->addr = mlx_get_data_addr(texture->texture,
			&(texture->bpp), &(texture->size_line),
			&(texture->endian));
	if (!texture->addr)
		return (ft_printf(_GET_ADDR), exit_w_code(1, data), NULL);
	return (texture);
}

static t_texture	*load_texture(t_data *data, char *asset_file, int size)
{
	t_texture	*texture;

	texture = ft_calloc(sizeof(t_texture));
	if (!texture)
		exit_w_code(1, data);
	texture->texture = xpm_img(data->win->mlx, asset_file, size);
	if (!texture->texture)
		return (free(texture), ft_printf(_ASSET_INIT), exit_w_code(1, data)
			, NULL);
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
	data->mini_texture[M_CLOSE] = load_texture(data, CLOSED_TEXTURE,
			TILE_SIZE);
	data->mini_texture[M_OPEN] = load_texture(data, OPEN_TEXTURE,
			TILE_SIZE);
	data->mini_texture[M_CHANGE] = load_texture(data, CHANGING_TEXTURE,
			TILE_SIZE);
}

void	get_wall_texture(t_data *data)
{
	data->texture[NO] = load_texture(data, data->text[NO], TEXTURE_SIZE);
	data->texture[SO] = load_texture(data, data->text[SO], TEXTURE_SIZE);
	data->texture[WE] = load_texture(data, data->text[WE], TEXTURE_SIZE);
	data->texture[EA] = load_texture(data, data->text[EA], TEXTURE_SIZE);
	data->door_textures[D_OPEN] = load_texture(data, DOOR_OPEN, TEXTURE_SIZE);
	data->door_textures[D_2] = load_texture(data, DOOR_2, TEXTURE_SIZE);
	data->door_textures[D_3] = load_texture(data, DOOR_3, TEXTURE_SIZE);
	data->door_textures[D_4] = load_texture(data, DOOR_4, TEXTURE_SIZE);
	data->door_textures[D_5] = load_texture(data, DOOR_5, TEXTURE_SIZE);
	data->door_textures[D_CLOSED] = load_texture(data, DOOR_CLOSED,
			TEXTURE_SIZE);
	data->door_text = load_door_text(data, DOOR_TEXT, DOOR_TEXT_WIDTH,
			DOOR_TEXT_HEIGHT);
}
