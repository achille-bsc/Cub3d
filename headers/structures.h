/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:37:32 by abosc             #+#    #+#             */
/*   Updated: 2025/08/26 17:02:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

enum e_pos_axis
{
	X,
	Y,
}	;

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;

typedef struct s_window
{
	void		*mlx;
	void		*window;
}				t_window;

typedef struct s_map
{
	char	**map;
}			t_map;

typedef struct s_movement
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
	bool	dir_up;
	bool	dir_down;
	bool	dir_left;
	bool	dir_right;
}			t_movement;

typedef struct s_data
{
	void		*texture[4];
	void		*mini_texture[4];
	size_t		old_time;
	size_t		time;
	t_movement	move;
	t_map		map;
	t_window	win;
	t_player	player;
}				t_data;

#endif
