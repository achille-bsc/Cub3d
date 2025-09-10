/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leane <leane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:44:10 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/10 23:39:15 by leane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_minimap_pixel_put(t_window *win, int x, int y, int color)
{
	if ((x >= WIDTH - MINIMAP_SIZE_X - MINIMAP_START_X && x < WIDTH
			- MINIMAP_START_X)
		&& (y >= MINIMAP_START_Y && y < MINIMAP_SIZE_Y + MINIMAP_START_Y))
		*(int *)(win->img_ptr + (y * win->line_length + x * (win->bpp
						/ 8))) = color;
}

void	my_mlx_pixel_put(t_window *win, int x, int y, int argb)
{
	int	alpha;

	alpha = (argb >> 24) & 0xFF;
	if (alpha == 0)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(win->img_ptr + (y * win->line_length + x * (win->bpp
						/ 8))) = argb;
}

int	get_color_from_texture(t_texture *texture, int x, int y)
{
	char	*pixel;
	int		bgra[4];
	int		color;

	pixel = texture->addr + (y * texture->size_line + x * (texture->bpp / 8));
	bgra[0] = (unsigned char)pixel[0];
	bgra[1] = (unsigned char)pixel[1];
	bgra[2] = (unsigned char)pixel[2];
	if (bgra[0] == 255 && bgra[1] == 0 && bgra[2] == 255)
		bgra[3] = 0;
	else
		bgra[3] = 255;
	color = bgra[3] << 24 | bgra[2] << 16 | bgra[1] << 8 | bgra[0];
	return (color);
}
