/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:33:54 by abosc             #+#    #+#             */
/*   Updated: 2025/08/30 14:59:00 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../../Depedencies/minilibx-linux/mlx.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MAP_WIDTH 24
#define MAP_HEIGHT 12
#define PI 3.141592
#define FOV 66

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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		*(int *)(data->addr + (y * data->line_length + x * (data->bpp / 8))) = color;
}

void calculate_plane(double dirX, double dirY, double fov, double *planeX, double *planeY)
{
    double fov_factor = tan((fov / 2) * PI / 180.0); // convert deg to radians and halve

    *planeX = -dirY * fov_factor;
    *planeY = dirX * fov_factor;
}

void	draw_frame(t_data *img, double posX, double posY, double dirX, double dirY, double planeX, double planeY)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		double sideDistX, sideDistY;
		int stepX, stepY;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		bool hit = false;
		int side;
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapY][mapX] > 0)
				hit = true;
		}

		double perpWallDist;
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;

		int color = (side == 1) ? 0x00FF00 : 0x800000;

		for (int y = drawStart; y < drawEnd; y++)
			my_mlx_pixel_put(img, x, y, color);
	}
}

int	main_loop(t_data *img)
{
	static double	posX = 11, posY = 6; // position initiale
	static double	dirX = 0.5, dirY = 0;
	static double	planeX , planeY;

	calculate_plane(dirX, dirY, FOV, &planeX, &planeY);
	img->img = mlx_new_image(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);

	draw_frame(img, posX, posY, dirX, dirY, planeX, planeY);

	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);

	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d - raycasting");

	mlx_loop_hook(img.mlx, main_loop, &img);
	mlx_hook(img.win, 17, (1L << 17), exit, 1);
	mlx_loop(img.mlx);
}
