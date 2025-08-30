/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datoia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:20:12 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:05:29 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_datoia(char	**darray, int args)
{
	int	i;
	int	*bufferi;

	if (!darray)
		return (NULL);
	bufferi = ft_calloc(args * sizeof(int));
	if (!bufferi)
		return (NULL);
	i = 0;
	while (darray[i])
	{
		bufferi[i] = ft_atoi(darray[i]);
		i++;
	}
	return (bufferi);
}
