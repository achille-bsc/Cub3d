/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:21:30 by abosc             #+#    #+#             */
/*   Updated: 2025/09/03 17:15:08 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_data *data)
{
	int			i;
	t_texture	*texture[4];

	i = 0;
	while (i < 4)
	{
		texture[i] = malloc(sizeof(t_texture));
		texture[i]->texture = mlx_xpm_file_to_image(data->win.mlx, data->text[i],
				(int *)TILE_SIZE, (int *)TILE_SIZE);
		texture[i]->addr = mlx_get_data_addr(texture[i]->texture,
				&(texture[i]->bpp), &(texture[i]->size_line),
				&(texture[i]->endian));
		data->texture[i] = texture[i];
		i++;
	}
}
