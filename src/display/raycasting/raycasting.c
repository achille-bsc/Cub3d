/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:53:23 by abosc             #+#    #+#             */
/*   Updated: 2025/09/04 17:41:35 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #include <math.h>

/*
Map temporaire (on feras une vrai map plus tard)
*/
#define MAP_WIDTH 24
#define MAP_HEIGHT 12

char worldMap[MAP_HEIGHT][MAP_WIDTH] =
{
	{"111111111111111111111111"},
	{"100000000000000000000111"},
	{"100000000000000000000011"},
	{"100000000000000000000001"},
	{"100000000000000000000001"},
	{"100000000000000000000001"},
	{"100000000000000000000001"},
	{"100000000000000000100001"},
	{"100000000000000000000001"},
	{"100000000000000000000001"},
	{"100000000000000000000001"},
	{"111111111111111111111111"}
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

	fov_factor = tan((FOV * M_PI / 180.0) / 2);
	player->plane[X] = player->vec[Y] * fov_factor;
	player->plane[Y] = player->vec[X] * fov_factor;
}

t_camera	*cam_val_setter(double pos[2], double vec[2], double plane[2],
		t_camera *cam, int x)
{
	cam = ft_calloc(sizeof(t_camera));
	cam->cameraX = 2 * x / (double)WIDTH - 1;
	cam->rayDirX = vec[X] + plane[X] * cam->cameraX;
	cam->rayDirY = vec[Y] + plane[Y] * cam->cameraX;
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
	(void)data;
	hit = false;
	// char **tab;

	// tab = (char **)worldMap;
	// for (int i = 0; tab[i] != NULL; i++ )
	// 	for (int ii = 0; ii < MAP_WIDTH ; ii++)
	// 		ft_printf_putnumber(tab[i][ii]);
	// tab = data->map.map;
	// for (int i = 0; tab[i] != NULL; i++ )
	// 	ft_putendl_fd(tab[i], 1);
	// ft_printf_putchar(data->map.map[cam->mapY][cam->mapX]);
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
		if (data->map.map[cam->mapY][cam->mapX] != '0')
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

int	get_pixel_from_texture(t_texture *texture, double texX, double texY)
{
	int pixel;
	int val;

	val = (texY * texture->size_line + texX * (texture->bpp / 8));

	// ft_putendl_fd(ft_itoa(val), 1);
	// ft_printf_putstr(texture->addr);
	// write(1, "\n", 1);
	pixel = texture->addr[val];
	return (pixel);
}

void	pixels_rendering(t_data *data, t_camera *cam, t_window win, double pos[2], int side,
		int x)
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	(void)data;
	// int		color;
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
	double wallX = pos[X] + perpWallDist * cam->rayDirX;
	wallX -= floor(wallX);
	for (int y = 0; y < drawStart; y++)
		my_mlx_pixel_put(win, x, y, 0x87CEEB); // bleu ciel
	if (side == 1)
	{
		if (cam->stepY >= 0)	// mur OUEST
		{
			// double texX = (int)(wallX * TILE_SIZE);
			// double step = 1.0 * TILE_SIZE / lineHeight;
			// double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
			for (int y = drawStart; y <= drawEnd; y++)
			{
				// double texY = (int)texPos & (TILE_SIZE - 1);
				// ft_printf_putstr(data->texture[WE]->addr);
				// write(1, "\n", 1);
				my_mlx_pixel_put(win, x, y, /*get_pixel_from_texture(data->texture[WE], texX, texY)*/0x333333);
				// texPos += step;
			}
		}
		else 				// mur EST
		{
			// double texX = (int)(wallX * TILE_SIZE);
			// double step = 1.0 * TILE_SIZE / lineHeight;
			// double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
			for (int y = drawStart; y <= drawEnd; y++)
			{
				// double texY = (int)texPos & (TILE_SIZE - 1);
				// ft_printf_putstr(data->texture[WE]->addr);
				// write(1, "\n", 1);
				my_mlx_pixel_put(win, x, y, /*get_pixel_from_texture(data->texture[WE], texX, texY)*/0x777777);
			}
		}
	}
	else
	{
		if (cam->stepX >= 0)	// mur SUD
		{
			// double texX = (int)(wallX * TILE_SIZE);
			// double step = 1.0 * TILE_SIZE / lineHeight;
			// double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
			for (int y = drawStart; y <= drawEnd; y++)
			{
				// double texY = (int)texPos & (TILE_SIZE - 1);
				// ft_printf_putstr(data->texture[WE]->addr);
				// write(1, "\n", 1);
				my_mlx_pixel_put(win, x, y, /*get_pixel_from_texture(data->texture[WE], texX, texY)*/0xbbbbbb);
			}
		}
		else				// mur NORD
		{
			// double texX = (int)(wallX * TILE_SIZE);
			// double step = 1.0 * TILE_SIZE / lineHeight;
			// double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
			for (int y = drawStart; y <= drawEnd; y++)
			{
				// double texY = (int)texPos & (TILE_SIZE - 1);
				// ft_printf_putstr(data->texture[WE]->addr);
				// write(1, "\n", 1);
				my_mlx_pixel_put(win, x, y, /* get_pixel_from_texture(data->texture[WE], texX, texY)*/0xffffff);
			}
		}
	}

		// --- COULEUR DU MUR ---
	// if (side == 1)
	// 	color = 0x00FF00; // vert
	// else
	// 	color = 0x800000; // rouge foncé

	// --- DESSIN DU CIEL (au-dessus du mur) ---


	// --- DESSIN DU MUR ---


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
		cam = cam_val_setter(pos, player->vec, player->plane, cam, x);
		rays_dir_setter(cam, pos);
		pixels_rendering(data, cam, win, pos, rays_calculator(cam, data), x);
		x++;
	}
}

void	image_drowing(t_window window, t_player *player, t_data *data)
{
	// static double	dir[2] = {0.5, 0};
	// static double	plane[2];

	// static double pos[2] = {11, 6};
		// Valeurs temp (avant d'avoir les mouvements)
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.img_ptr = mlx_get_data_addr(window.img, &window.bit_by_pix,
			&window.line_length, &window.endian);
	draw_frame(window, player->pos, player, data);
	mlx_put_image_to_window(window.mlx, window.window, window.img, 0, 0);
	mlx_destroy_image(window.mlx, window.img);
}

void	raycasting(t_data *datas)
{
	t_player *player;

	player = datas->player;
	// player->pos[X] = 10;
	// // player->pos[Y] = 5;
	// double angle;
	// angle = -2;
	// vecteur direction unitaire
	// double oldDirX = player->dir;
	// player->dir = player->dir * cos(angle) - player->dir[Y] * sin(angle);
	// player->dir[Y] = oldDirX * sin(angle) + player->dir[Y] * cos(angle);
	player->vec[X] = cos(player->dir);
	player->vec[Y] = sin(player->dir);


	// calcule un plan perpendiculaire au vecteur dir
	calculate_plane(player);


	// calculate_plane(player);
	image_drowing(datas->win, player, datas);
}


