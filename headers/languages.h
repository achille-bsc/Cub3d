/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   languages.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:36:02 by abosc             #+#    #+#             */
/*   Updated: 2025/08/29 02:07:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANGUAGES_H
# define LANGUAGES_H

/* GAME INFOS */

# define NAME				"My Little Adventure ! Second Coming !"

/* ERRORS */

# define _ARGS				"Fatal error: cub3d takes 2 args\n"
# define _FILE_EXTENTION	"Fatal error: bad file extention\n"
# define _FILE				"Fatal error: failed to open \"%s\"\n"
# define _EMPTY_FILE		"Fatal error: opened file is empty\n"
# define _RGB				"Fatal error: please put red, green, and blue\
 values\n"
# define _RGB_RANGE			"Fatal error: rgb value must be between 0 and 255\n"

# define _CEILING			"Fatal error: failed to init ceiling color\n"
# define _FLOOR				"Fatal error: failed to init floor color\n"
# define _NORTH				"Fatal error: failed to init the north texture\n"
# define _SOUTH				"Fatal error: failed to init the south texture\n"
# define _WEST				"Fatal error: failed to init the west texture\n"
# define _EAST				"Fatal error: failed to init the east texture\n"
# define _MAP_DATA			"Fatal error: failed to get map data\n"

# define _MLXINIT			"Fatal error: failed to init mlx\n"
# define _IMGINIT			"Fatal error: failed to init image\n"
# define _ASSET_INIT		"Fatal error: failed to init asset n°%i\n"

#endif
