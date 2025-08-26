/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:35:39 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/14 03:25:02 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freedarray(char **darray)
{
	int	i;

	i = 0;
	if (!darray)
		return ;
	while (darray[i])
		ft_str_reset(&darray[i++]);
	free(darray);
	darray = NULL;
}
