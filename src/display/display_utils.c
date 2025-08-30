/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:05:29 by abosc             #+#    #+#             */
/*   Updated: 2025/08/28 20:33:02 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	*xpm_img(void *mlx, char *path, int size)
{
	return (mlx_xpm_file_to_image(mlx, path, &size, &size));
}
