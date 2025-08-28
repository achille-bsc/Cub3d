/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:35:25 by abosc             #+#    #+#             */
/*   Updated: 2025/08/28 05:04:22 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

/* PARSING */

bool	parser(t_data *data, char *map_path);
bool	parse_data(t_data *data, char **file);

/* MINIMAP */

void	minimap_handling(t_data *data);

/* UTILS */

char	*skipchar(char *src, int offset, char skiped);
void	*xpm_img(void *mlx, char *path, int size);

/* DISPLAY */

bool	display(t_data *data);

/* GAMEPLAY */

void	events(t_data *data);

/* EXIT */

int		clean_quit(t_data *data);
void	exit_w_code(int code, t_data *data);
void	free_str_array(char *src[]);


#endif
