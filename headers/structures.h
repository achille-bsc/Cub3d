/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:37:32 by abosc             #+#    #+#             */
/*   Updated: 2025/08/29 01:38:05 by lvan-bre         ###   ########.fr       */
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

enum e_img_orientation
{
	NO,
	SO,
	WE,
	EA,
	NUL,
}	;

typedef enum e_parsing_errors
{
	ERR_CEILING,
	ERR_FLOOR,
	ERR_NORTH,
	ERR_SOUTH,
	ERR_WEST,
	ERR_EAST,
	DISPATCH_OK,
}	t_parsing_errors;

enum e_up_down
{
	FLOOR,
	CEILING,
	PLAYER,
}	;

enum e_colors
{
	RED,
	GREEN,
	BLUE,
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
	char		*text[4];
	void		*texture[4];
	void		*mini_texture[4];
	char		*colors[2];
	int			rgb[3];
	size_t		old_time;
	size_t		time;
	t_movement	move;
	t_map		map;
	t_window	win;
	t_player	player;
}				t_data;

#endif
