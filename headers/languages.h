/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   languages.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leane <leane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:36:02 by abosc             #+#    #+#             */
/*   Updated: 2025/09/11 00:53:42 by leane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANGUAGES_H
# define LANGUAGES_H

/* GAME INFOS */

# define NAME				"My Little Adventure ! Second Coming !"

/* MINIMAP TEXTURE */

# define FLOOR_TEXTURE		"assets/black.xpm"
# define OUT_TEXTURE		"assets/Lava.xpm"
# define WALL_TEXTURE		"assets/cobble.xpm"
# define CLOSED_TEXTURE     "assets/red_wool.xpm"
# define OPEN_TEXTURE     "assets/green_wool.xpm"

# define DOOR_OPEN          "assets/Door-6.xpm"
# define DOOR_CLOSED         "assets/Door-1.xpm"

/* ERRORS */

# define _ARGS				"Fatal error: cub3d takes 1 args\n"
# define _FILE_EXTENSION	"Fatal error: invalid file extention \
(expected .cub)\n"
# define _FILE				"Fatal error: failed to open \"%s\"\n"
# define _EMPTY_FILE		"Fatal error: opened file is empty\n"
# define _RGB_FORMAT		"Fatal error: please put red, green, and blue\
 values\n"
# define _RGB_RANGE			"Fatal error: rgb value must be between 0 and 255\n"

# define _CEILING			"Fatal error: failed to init ceiling color\n"
# define _FLOOR				"Fatal error: failed to init floor color\n"
# define _NORTH				"Fatal error: failed to init the north texture\n"
# define _SOUTH				"Fatal error: failed to init the south texture\n"
# define _WEST				"Fatal error: failed to init the west texture\n"
# define _EAST				"Fatal error: failed to init the east texture\n"
# define _MAP_DATA			"Fatal error: failed to get map data\n"

# define _MAP_CHAR			"Fatal error: unknown char '%c' in map \n"
# define _MULTI_PLAYER		"Fatal error: multi player spawn not supported by \
cub3d\n"
# define _NO_SPAWN			"Fatal error: no spawn found\n"
# define _OPEN_MAP			"Fatal error: open map : (%i,%i)\n"
# define _DOOR_NEXT_TO_VOID "Fatal error: door is next to void : (%i,%i)\n"

# define _MLXINIT			"Fatal error: failed to init mlx\n"
# define _WININIT			"Fatal error: failed to init window\n"
# define _IMGINIT			"Fatal error: failed to init image\n"
# define _ASSET_INIT		"Fatal error: failed to init texture\n"
# define _GET_ADDR			"Fatal error: failed to get address from image\n"

#endif
