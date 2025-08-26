/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:20:13 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/01 00:25:36 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strn_replace(char *sent, int sizemax)
{
	char	*buffer;

	if (!sent)
		return (ft_strdup(""));
	buffer = ft_strndup(sent, sizemax);
	free(sent);
	return (buffer);
}
