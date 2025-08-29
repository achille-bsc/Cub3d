/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:34:25 by abosc             #+#    #+#             */
/*   Updated: 2025/08/29 07:53:45 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/keysym.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"
# include "languages.h"
# include "structures.h"
# include "functions.h"

# define HEIGHT				1080
# define WIDTH				1920
# define RENDER_DIST
# define MAX_FPS			60
# define FOV				66
# define MV_SPEED			0.2
# define ROT_SPEED
# define TILE_SIZE			20

# define KEYPRESS			2
# define KEYRELEASE			3
# define ESCAPE				17

#endif
