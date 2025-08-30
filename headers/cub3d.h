/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:34:25 by abosc             #+#    #+#             */
/*   Updated: 2025/08/28 18:08:06 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/keysym.h>
# include <fcntl.h>
#include <math.h>

# include "mlx.h"
# include "libft.h"
# include "languages.h"
# include "structures.h"
# include "functions.h"

# define HEIGHT				1080
# define WIDTH				1920
# define RENDER_DIST
# define FPS_MAX			60
# define FOV				90
# define MV_SPEED			0.2
# define ROT_SPEED

# define KEYPRESS			2
# define KEYRELEASE			3
# define ESCAPE				17

# ifndef M_PI
#  define M_PI 3.14159265358979323846f
# endif

#endif