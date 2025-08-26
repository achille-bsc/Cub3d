/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:24:12 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/22 03:27:53 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_strnfdup - Duplicates a string up to a given size.
	Frees the original string after duplication.
	Returns the newly allocated copy or NULL on failure.
*/
char	*ft_strnfdup(char *src, int size)
{
	char	*buffer;

	buffer = ft_strndup(src, size);
	ft_str_reset(&src);
	return (buffer);
}
