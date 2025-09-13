/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:44:10 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 06:38:47 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_transparency(t_data *data, int x, int y)
{
	int		*dst_ptr;
	int		dst;
	double	a;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	if (data->bck_color->alpha == 0)
		return ((void)ft_printf("returning...\n"));
	dst_ptr = (int *)(data->win->img_ptr + (y * data->win->line_length + x
				* (data->win->bpp / 8)));
	dst = *dst_ptr;
	data->bck_color->bckgrnd_r = (dst >> 16) & 0xFF;
	data->bck_color->bckgrnd_g = (dst >> 8) & 0xFF;
	data->bck_color->bckgrnd_b = dst & 0xFF;
	a = data->bck_color->alpha / 255.0;
	data->bck_color->r = (int)(data->bck_color->src_r * a
			+ data->bck_color->bckgrnd_r * (1 - a));
	data->bck_color->g = (int)(data->bck_color->src_g * a
			+ data->bck_color->bckgrnd_g * (1 - a));
	data->bck_color->b = (int)(data->bck_color->src_b * a
			+ data->bck_color->bckgrnd_b * (1 - a));
	*dst_ptr = (0xFF << 24) | (data->bck_color->r << 16)
		| (data->bck_color->g << 8) | data->bck_color->b;
}

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
