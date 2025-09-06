/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:44:10 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 12:23:36 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_minimap_pixel_put(t_window win, int x, int y, int color)
{
	if ((x >= WIDTH - MINIMAP_SIZE_X && x < WIDTH)
		&& (y >= 0 && y < MINIMAP_SIZE_Y))
		*(int *)(win.img_ptr + (y * win.line_length + x * (win.bpp
						/ 8))) = color;
}

void	my_mlx_pixel_put(t_window win, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(win.img_ptr + (y * win.line_length + x * (win.bpp
						/ 8))) = color;
}

int	get_color_from_texture(t_texture *texture, int x, int y)
{
	char	*color;

	color = texture->addr + (y
			* texture->size_line + x * (texture->bpp / 8));
	return (*(unsigned int *)color);
}
