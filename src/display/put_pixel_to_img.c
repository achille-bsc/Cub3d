/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:44:10 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/09 13:20:09 by sellith          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	if (color == 0)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(win->img_ptr + (y * win->line_length + x * (win->bpp
						/ 8))) = color;
}

int	get_color_from_texture(t_texture *texture, int x, int y)
{
	char	*color;

	color = texture->addr + (y
			* texture->size_line + x * (texture->bpp / 8));
	return (*(unsigned int *)color);
}
