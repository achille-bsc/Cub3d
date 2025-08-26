/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:24:40 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:04:55 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (ft_printf("%s", ERR_MALLOC), NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	const size_t	count = 10;
// 	const size_t	size = sizeof(int);
// 	int				*ptr;
// 	size_t			i;

// 	i = 0;
// 	ptr = (int *)ft_calloc(count, size);
// 	if (!ptr)
// 	{
// 		free(ptr);
// 		return (1);
// 	}
// 	while (i < count)
// 	{
// 		if (ptr[i] != 0)
// 		{
// 			printf("[ko] not zero at index %zu\n", i);
// 			break ;
// 		}
// 		i++;
// 	}
// 	printf("[ok]\n");
// 	free(ptr);
// 	return (0);
// }
