/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellith <sellith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:34:25 by abosc             #+#    #+#             */
/*   Updated: 2025/09/08 22:26:07 by sellith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>

# include "mlx.h"
# include "libft.h"
# include "languages.h"
# include "structures.h"
# include "functions.h"
# include "sys/time.h"

# define HEIGHT					1080
# define WIDTH					1920
# define RENDER_DIST
# define FPS_MAX				200
# define FOV					90
# define MV_SPEED				0.05
# define ROT_SPEED				0.08

# define TILE_SIZE				20
# define TEXTURE_SIZE			64

# define KEYPRESS				2
# define KEYRELEASE				3
# define ESCAPE					17

# define MINIMAP_START_X        20
# define MINIMAP_START_Y        20
# define MINIMAP_SIZE_X			500
# define MINIMAP_SIZE_Y			300
# define MINIMAP_BORDER_SIZE	5

# define ONE_SEC				1000
# ifndef M_PI
#  define M_PI 3.14159265358979323846f
# endif

#endif
