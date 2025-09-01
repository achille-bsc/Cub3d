/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:53:23 by abosc             #+#    #+#             */
/*   Updated: 2025/09/01 17:07:43 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #include <math.h>

/*
Map temporaire (on feras une vrai map plus tard)
*/
#define MAP_WIDTH 24
#define MAP_HEIGHT 12

int worldMap[MAP_HEIGHT][MAP_WIDTH] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*
+ On calcule le FOV
	/ 2 (angle entre la direction de la cam et le bor de l'ecran)
+ On passe des degres en radiant en multipliant par (PI / 180)
+ Ce facteur sert à déterminer la largeur du plan de projection selon le FOV.
+ Calcul de plan (calcul de vecteurs perpendiculaire au vecteur direction)
*/
void	calculate_plane(t_player *player)
{
	double	fov_factor;

	fov_factor = tan((FOV / 2) * M_PI / 180.0);
	player->plane[X] = -player->dir[Y] * fov_factor;
	player->plane[Y] = player->dir[X] * fov_factor;
}

t_camera	*cam_val_setter(double pos[2], double dir[2], double plane[2],
		t_camera *cam, int x)
{
	cam = ft_calloc(sizeof(t_camera));
	cam->cameraX = 2 * x / (double)WIDTH - 1;
	cam->rayDirX = dir[X] + plane[X] * cam->cameraX;
	cam->rayDirY = dir[Y] + plane[Y] * cam->cameraX;
	cam->mapX = (int)pos[X];
	cam->mapY = (int)pos[Y];
	cam->deltaDistX = fabs(1 / cam->rayDirX);
	cam->deltaDistY = fabs(1 / cam->rayDirY);
	// cam->sideDistX;
	// cam->sideDistY;
	cam->stepX = 0;
	cam->stepY = 0;
	return (cam);
}

void	rays_dir_setter(t_camera *cam, double pos[2])
{
	if (cam->rayDirX < 0)
	{
		cam->stepX = -1;
		cam->sideDistX = (pos[X] - cam->mapX) * cam->deltaDistX;
	}
	else
	{
		cam->stepX = 1;
		cam->sideDistX = (cam->mapX + 1.0 - pos[X]) * cam->deltaDistX;
	}
	if (cam->rayDirY < 0)
	{
		cam->stepY = -1;
		cam->sideDistY = (pos[Y] - cam->mapY) * cam->deltaDistY;
	}
	else
	{
		cam->stepY = 1;
		cam->sideDistY = (cam->mapY + 1.0 - pos[Y]) * cam->deltaDistY;
	}
}

int	rays_calculator(t_camera *cam, t_data *data)
{
	bool	hit;
	int		side;

	hit = false;
	while (!hit)
	{
		if (cam->sideDistX < cam->sideDistY)
		{
			cam->sideDistX += cam->deltaDistX;
			cam->mapX += cam->stepX;
			side = 0;
		}
		else
		{
			cam->sideDistY += cam->deltaDistY;
			cam->mapY += cam->stepY;
			side = 1;
		}
		if (data->map.i_map[cam->mapY][cam->mapX] > 0)
			hit = true;
	}
	return (side);
}

void	my_mlx_pixel_put(t_window win, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(win.img_ptr + (y * win.line_length + x * (win.bit_by_pix
						/ 8))) = color;
}

void	pixels_rendering(t_camera *cam, t_window win, double pos[2], int side,
		int x)
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	perpWallDist;

	if (side == 0)
		perpWallDist = (cam->mapX - pos[X] + (1 - cam->stepX) / 2)
			/ cam->rayDirX;
	else
		perpWallDist = (cam->mapY - pos[Y] + (1 - cam->stepY) / 2)
			/ cam->rayDirY;
	lineHeight = (int)(HEIGHT / perpWallDist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	if (side == 1)
		color = 0xF03A3A;
	else
		color = 0xF0593A;

		// --- COULEUR DU MUR ---
	// if (side == 1)
	// 	color = 0x00FF00; // vert
	// else
	// 	color = 0x800000; // rouge foncé

	// --- DESSIN DU CIEL (au-dessus du mur) ---
	for (int y = 0; y < drawStart; y++)
		my_mlx_pixel_put(win, x, y, 0x87CEEB); // bleu ciel

	// --- DESSIN DU MUR ---
	for (int y = drawStart; y <= drawEnd; y++)
		my_mlx_pixel_put(win, x, y, color);

	// --- DESSIN DU SOL (en dessous du mur) ---
	for (int y = drawEnd + 1; y < HEIGHT; y++)
		my_mlx_pixel_put(win, x, y, 0x444444); // gris foncé
	// while (drawStart < drawEnd)
	// 	my_mlx_pixel_put(win, x, drawStart++, color);
}

void	draw_frame(t_window win, double pos[2], t_player *player, t_data *data)
{
	int			x;
	// int			drawStart;
	// int			drawEnd;
	t_camera	*cam;

	x = 0;
	while (x < WIDTH)
	{
		cam = cam_val_setter(pos, player->dir, player->plane, cam, x);
		rays_dir_setter(cam, pos);
		pixels_rendering(cam, win, pos, rays_calculator(cam, data), x);
		x++;
	}
}

void	image_drowing(t_window window, t_player *player, t_data *data)
{
	// static double	dir[2] = {0.5, 0};
	// static double	plane[2];

	static double pos[2] = {11, 6};
		// Valeurs temp (avant d'avoir les mouvements)
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.img_ptr = mlx_get_data_addr(window.img, &window.bit_by_pix,
			&window.line_length, &window.endian);
	draw_frame(window, pos, player, data);
	mlx_put_image_to_window(window.mlx, window.window, window.img, 0, 0);
	mlx_destroy_image(window.mlx, window.img);
}

void	raycasting(t_data *datas)
{
	t_player *player;

	player = datas->player;
	// player->pos[X] = 11;
	// player->pos[Y] = 6;
	// player->dir[X] = 0.5;
	// player->dir[Y] = 0;

	player->pos[X] = 1;
	player->pos[Y] = 1;

	// vecteur direction unitaire
	player->dir[X] = -1;  // regarde vers la gauche
	player->dir[Y] = 0;

	// calcule un plan perpendiculaire au vecteur dir
	calculate_plane(player);


	calculate_plane(player);
	image_drowing(datas->win, player, datas);
}