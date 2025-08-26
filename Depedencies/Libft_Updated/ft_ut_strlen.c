/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ut_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 04:23:38 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/23 04:30:02 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (ft_printf("Please enter at least one str"), 1);
	i = 1;
	while (i < ac)
		ft_printf("%d\n", ft_strlen(av[i++]));
	return (0);
}
