/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:05:01 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/08/29 02:07:28 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] == ' ')
		i++;
	if (file[i] == 'N' || file[i] == 'S' || file[i] == 'W' || file[i] == 'E' )
		i++;
	if (file[i] != '0' && file[i] != '1' )
		return (false);
	return (true);
}

static t_parsing_errors	is_all_data_parsed(t_data *data)
{
	if (!data->colors[CEILING])
		return (ERR_CEILING);
	if (!data->colors[FLOOR])
		return (ERR_FLOOR);
	if (!data->text[NO])
		return (ERR_NORTH);
	if (!data->text[SO])
		return (ERR_SOUTH);
	if (!data->text[WE])
		return (ERR_WEST);
	if (!data->text[EA])
		return (ERR_EAST);
	return (DISPATCH_OK);
}

static bool	parse_colors(t_data *data, char *file)
{
	if (ft_strncmp("C ", file, 2) == 0)
	{
		data->colors[CEILING] = skipchar(file, 1, ' ');
		if (!data->colors[CEILING])
			return (false);
	}
	else if (ft_strncmp("F ", file, 2) == 0)
	{
		data->colors[FLOOR] = skipchar(file, 1, ' ');
		if (!data->colors[FLOOR])
			return (false);
	}
	return (true);
}

static bool	parse_img(t_data *data, char *file)
{
	if (ft_strncmp("NO ", file, 3) == 0)
	{
		data->text[NO] = skipchar(file, 2, ' ');
		if (!data->text[NO])
			return (false);
	}
	else if (ft_strncmp("SO ", file, 3) == 0)
	{
		data->text[SO] = skipchar(file, 2, ' ');
		if (!data->text[SO])
			return (false);
	}
	else if (ft_strncmp("WE ", file, 3) == 0)
	{
		data->text[WE] = skipchar(file, 2, ' ');
		if (!data->text[WE])
			return (false);
	}
	else if (ft_strncmp("EA ", file, 3) == 0)
	{
		data->text[EA] = skipchar(file, 2, ' ');
		if (!data->text[EA])
			return (false);
	}
	return (true);
}

bool	dispatch_data(t_data *data, char **file)
{
	t_parsing_errors	res;
	int					i;

	i = 0;
	while (file[i])
	{
		if (!parse_img(data, file[i]))
			return (false);
		if (!parse_colors(data, file[i]))
			return (false);
		res = is_all_data_parsed(data);
		if (is_map(file[i]) && res == DISPATCH_OK)
		{
			data->map.map = ft_arraydup(file + i);
			if (!data->map.map)
				return (false);
			return (true);
		}
		else if (is_map(file[i]) && res != DISPATCH_OK)
			return (dispatch_error_handling(res), false);
		i++;
	}
	return (ft_printf(_MAP_DATA), false);
}
