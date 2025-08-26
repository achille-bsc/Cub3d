/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoining.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:25:14 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/27 22:29:49 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoining(char *dest, char *src1, char *src2)
{
	char	*buffer;

	buffer = ft_strjoining(dest, src1);
	buffer = ft_strjoining(buffer, src2);
	return (buffer);
}
