/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:13:34 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/08/28 21:05:47 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dispatch_error_handling(t_parsing_errors err)
{
	if (err == ERR_CEILING)
		ft_printf(_CEILING);
	if (err == ERR_FLOOR)
		ft_printf(_FLOOR);
	if (err == ERR_NORTH)
		ft_printf(_NORTH);
	if (err == ERR_SOUTH)
		ft_printf(_SOUTH);
	if (err == ERR_WEST)
		ft_printf(_WEST);
	if (err == ERR_EAST)
		ft_printf(_EAST);
}
