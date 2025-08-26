/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:10:49 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/21 22:47:31 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_atoul - Converts a string to an unsigned long.
	Handles optional leading whitespace and sign characters.
	Stops conversion at the first non-digit character.
*/
unsigned long	ft_atoul(const char *nptr)
{
	long			tmp;

	if (!nptr)
		return (0);
	tmp = ft_atol(nptr);
	return ((unsigned long)tmp);
}
