/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdarray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:35:45 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 05:10:31 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putdarray(char **darray)
{
	int	i;

	i = 0;
	while (darray[i])
	{
		ft_printf_putstr(darray[i++]);
		write(1, "\n", 1);
	}
	return (i);
}

int	ft_printf_putdarray_fd(int fd, char **darray)
{
	int	i;

	i = 0;
	while (darray[i])
	{
		ft_printf_putstr_fd(fd, darray[i++]);
		write(fd, "\n", 1);
	}
	return (i);
}

char	*ft_strmerge(char **darray)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (darray[i])
	{
		res = ft_strjoining(res, darray[i]);
		if (!res)
			return (NULL);
		if (darray[i + 1])
		{
			res = ft_strjoining(res, "\n");
			if (!res)
				return (NULL);
		}
		i++;
	}
	return (res);
}
