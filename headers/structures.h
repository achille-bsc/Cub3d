/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:37:32 by abosc             #+#    #+#             */
/*   Updated: 2025/09/09 16:44:01 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

enum					e_door_status
{
	CLOSED,
	OPEN,
};

enum					e_extremes
{
	BEGIN,
	END,
};

enum					e_pos_axis
{
	X,
	Y,
	DIRX,
	DIRZ,
};

typedef enum e_mini_text
{
	M_FLOOR,
	M_WALL,
	M_OUT,
}						t_mini_text;

typedef struct s_camera
{
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				side_dist_x;
	double				side_dist_y;
	int					step_x;
	int					step_y;
}						t_camera;

typedef enum e_img_orientation
{
	NO,
	SO,
	WE,
	EA,
	NUL,
}						t_img_orientation;

typedef enum e_parsing_errors
{
	ERR_CEILING,
	ERR_FLOOR,
	ERR_NORTH,
	ERR_SOUTH,
	ERR_WEST,
	ERR_EAST,
	DISPATCH_OK,
}						t_parsing_errors;

enum					e_up_down
{
	FLOOR,
	CEILING,
	PLAYER,
};

enum					e_colors
{
	RED,
	GREEN,
	BLUE,
};

typedef struct s_player
{
	double				pos[2];
	double				dir;
	double				dirz;
	double				plane[2];
	double				vec[2];
	double				spawn[4];
	int					**map;
	int					sprint;
}						t_player;

typedef struct s_window
{
	void				*mlx;
	void				*window;
	void				*img;
	char				*img_ptr;
	int					bpp;
	int					line_length;
	int					endian;
	double				fov_factor;
}						t_window;

typedef struct s_map
{
	char				**map;
	int					**i_map;
	char				**dummy;
	int					size_x;
	int					size_y;
	int					extremities_x[2];
	int					extremities_y[2];
}						t_map;

typedef struct s_movement
{
	bool				forward;
	bool				backward;
	bool				left;
	bool				right;
	bool				dir_up;
	bool				dir_down;
	bool				dir_left;
	bool				dir_right;
	bool				sprint;
	bool				debug;
	bool				display_minimap;
}						t_movement;

typedef struct s_texture
{
	void				*texture;
	char				*addr;
	int					bpp;
	int					size_line;
	int					endian;
}						t_texture;

typedef struct s_pixel_rendering
{
	double				perp_wall_dist;
	double				wall_x;
	double				tex_x;
	double				step;
	double				tex_pos;
	double				tex_y;
}						t_pixel_rendering;

typedef struct s_vars
{
	int					draw[2];
	int					line_height;
	int					side;
	int					x;
}						t_vars;

typedef struct s_data
{
	char				*text[4];
	t_texture			*texture[4];
	t_texture			*mini_texture[4];
	t_texture			*door_textures[2];
	char				*colors[2];
	int					rgb[3];
	size_t				fps_counter;
	size_t				old_time;
	size_t				time;
	t_movement			move;
	t_map				map;
	t_window			*win;
	t_player			*player;
	t_pixel_rendering	*w_rendering;
	t_pixel_rendering	*d_rendering;
	t_camera			*door;
	t_camera			*cam;
	t_vars				*vars;
}						t_data;

#endif