/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:21:30 by abosc             #+#    #+#             */
/*   Updated: 2025/09/03 23:57:15 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_data *data)
{
	int			i;
	int			w;
	int			h;
	t_texture	*texture[4];

	i = 0;
	while (i < 4)
	{
		ft_printf("%s\n", data->text[i]);
		texture[i] = ft_calloc(sizeof(t_texture *));
		texture[i]->texture = mlx_xpm_file_to_image(data->win.mlx,
				data->text[i], &w, &h);
		texture[i]->addr = mlx_get_data_addr(texture[i]->texture,
				&(texture[i]->bpp), &(texture[i]->size_line),
				&(texture[i]->endian));
		data->texture[i] = texture[i];
		i++;
	}
}
