/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:35:25 by abosc             #+#    #+#             */
/*   Updated: 2025/09/13 07:27:28 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

/* PARSING */

bool				parser(t_data *data, char *map_path);
bool				dispatch_data(t_data *data, char **file);
void				dispatch_error_handling(t_parsing_errors err);
bool				map_parsing(t_data *data, char **map);
bool				player_four_dirs(t_data *data);

/* MINIMAP */

void				minimap_handling(t_data *data, t_window *win);
void				get_minimap_texture(t_data *data);
void				my_minimap_pixel_put(t_window *win, int x, int y,
						int color);
void				put_tile(t_texture *text, t_window *win, int x, int y);
void				put_first_layer(t_data *data, t_window *win);
void				minimap_put_borders_x(t_window *win);
void				minimap_put_borders_y(t_window *win);
void				put_centered_player(t_window *win, int color);
void				put_moving_player(t_data *data, t_window *win,
						int start[2]);
void				dp_centered(t_data *data, t_window *win, int diff[2]);
void				dp_full_offset(t_data *data, t_window *win);

/* UTILS */

char				*skipchar(char *src, int offset, char skiped);
void				*xpm_img(void *mlx, char *path, int size);
unsigned long long	get_time(void);
bool				is_spawn(char c);
bool				is_map(char c);
void				get_wall_texture(t_data *data);
void				print_debug_infos(t_data *data);
void				get_longer_str(t_data *data, char **map);
void				land_height(t_data *data, char **map);
int					get_nmb_of_doors(t_camera *cam, char **map);
void				ft_freecam(void **matrix);
bool				is_voided_door(char c);

/* MATHS */

double				to_deg(double rad);
double				to_rad(double deg);
void				calculate_plane(t_data *data, t_player *player);

/* DISPLAY */

bool				display(t_data *data);
void				init_cam_structs(t_data *data);
void				cam_val_setter(t_player *player, t_camera *cam, int x);
void				rays_dir_setter(t_camera *cam, double pos[2]);
void				rays_dist_calculator(t_data *data, t_camera *cam,
						t_camera **door, char **map);
void				draw_frame(t_player *player, t_data *data);
void				my_mlx_pixel_put(t_window *win, int x, int y, int color);
int					get_color_from_texture(t_texture *texture, int x, int y);
void				select_texture(t_data *data, t_camera *cam,
						t_rendering *rendering);
void				pixel_put_transparency(t_data *data, int x, int y);

/* GAMEPLAY */

void				events(t_data *data);
void				player_move(t_window *win, t_map map, t_player *player,
						t_movement move);
void				turning_cam(t_window *win, t_player *player,
						t_movement move);
int					minimap_display(t_data *data);
int					debug_info(t_data *data);
int					re_center_cam(t_data *data);
int					respawn(t_data *data);
int					door_action(double pos[2], char **map);
void				change_door_status(t_map *map);

/* EXIT */

void				exit_w_code(int code, t_data *data);
void				free_pars_info(t_data *data);
void				free_textures_3(t_data *data);

#endif
