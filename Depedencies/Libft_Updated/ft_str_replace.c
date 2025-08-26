/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:52:25 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/02 05:24:35 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_replace(char **dest, char *src)
{
	char	*buffer;

	if (!src)
	{
		ft_str_reset(dest);
		return ;
	}
	buffer = ft_strdup(src);
	ft_str_reset(dest);
	*dest = ft_strfdup(buffer);
	return ;
}
