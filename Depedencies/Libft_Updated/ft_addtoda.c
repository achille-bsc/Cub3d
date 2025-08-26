/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtoda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:25:15 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:04:25 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**initdarray(char *str)
{
	char	**buffer;

	buffer = ft_calloc(2 * sizeof(char *));
	if (!buffer)
		return (NULL);
	buffer[0] = ft_strdup(str);
	if (!buffer[0])
		return (free(buffer), NULL);
	buffer[1] = NULL;
	return (buffer);
}

char	**ft_addtoda(char **darray, char *str)
{
	int		alen;
	int		i;
	char	**buffer;

	alen = ft_darraylen(darray);
	i = 0;
	if (!darray)
		return (initdarray(str));
	buffer = ft_calloc(sizeof(char *) * (alen + 2));
	if (!buffer)
		return (NULL);
	while (darray[i])
	{
		buffer[i] = ft_strdup(darray[i]);
		if (!buffer[i])
			return (ft_freedarray(buffer), NULL);
		i++;
	}
	buffer[i] = ft_strdup(str);
	if (!buffer[i])
		return (ft_freedarray(buffer), NULL);
	buffer[i + 1] = NULL;
	if (darray)
		ft_freedarray(darray);
	return (buffer);
}
