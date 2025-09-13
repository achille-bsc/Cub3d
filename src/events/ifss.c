/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:25:03 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/13 09:40:37 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ifss(t_map map, int pos_x, int pos_y)
{
	if (map.map[(int)pos_y][pos_x]
		&& map.map[(int)pos_y][pos_x] != '1'
		&& map.map[(int)pos_y][pos_x] != ' '
		&& map.map[(int)pos_y][pos_x] != 'C')
		return (true);
	return (false);
}
