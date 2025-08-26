/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:25:14 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/27 22:28:31 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoin(char *dest, char *src1, char *src2)
{
	char	*buffer;

	buffer = ft_strjoin(dest, src1);
	buffer = ft_strjoining(buffer, src2);
	return (buffer);
}
