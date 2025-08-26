/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:35:25 by abosc             #+#    #+#             */
/*   Updated: 2025/08/26 18:13:46 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"


/* MINIMAP */

void	minimap_handling(t_data *data);

/* DISPLAY UTILS */

void	*xpm_img(void *mlx, char *path, int size);

/* DISPLAY */

bool	display(t_data *data);

/* GAMEPLAY */

void	events(t_data *data);

/* EXIT */

int		clean_quit(t_data *data);
void	exit_w_code(int code, t_data *data);


#endif
