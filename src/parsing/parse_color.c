/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:52:47 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 16:12:18 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_rgb_value(int color)
{
	if (color < 0 || color > 255)
		return (ft_printf(_RGB_RANGE), false);
	return (true);
}

void	check_color_chars(t_data *data, char *color)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (color[i])
	{
		if (!ft_isnum(color[i]) && color[i] != ',')
			(ft_printf(_NUMERIC_COLOR), exit_w_code(1, data));
		if (color[i] == ',')
			commas++;
		i++;
	}
	if (commas > 2)
		(ft_printf(_TOO_MUCH_COMMAS), exit_w_code(1, data));
}

void	parse_colors(t_data *data, char **color, int i)
{
	int	rgb[3];

	rgb[RED] = ft_atoi(color[RED]);
	rgb[GREEN] = ft_atoi(color[GREEN]);
	rgb[BLUE] = ft_atoi(color[BLUE]);
	ft_freedarray(color);
	if (!is_rgb_value(rgb[RED]) || !is_rgb_value(rgb[GREEN])
		|| !is_rgb_value(rgb[BLUE]))
		exit_w_code(1, data);
	data->rgb[i] = (255 << 24) + (rgb[RED] << 16) + (rgb[GREEN] << 8)
		+ rgb[BLUE];
}
