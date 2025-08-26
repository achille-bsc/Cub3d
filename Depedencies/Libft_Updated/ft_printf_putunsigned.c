/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:02:41 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:09:39 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putunsigned(unsigned int nmb)
{
	int		res;
	int		i;
	char	dest[10];

	i = 0;
	while (nmb >= 10)
	{
		dest[i++] = nmb % 10 + '0';
		nmb /= 10;
	}
	dest[i] = nmb + '0';
	res = i + 1;
	while (i >= 0)
		ft_printf_putchar(dest[i--]);
	return (res);
}

int	ft_printf_putunsigned_fd(int fd, unsigned int nmb)
{
	int		res;
	int		i;
	char	dest[10];

	i = 0;
	while (nmb >= 10)
	{
		dest[i++] = nmb % 10 + '0';
		nmb /= 10;
	}
	dest[i] = nmb + '0';
	res = i + 1;
	while (i >= 0)
		ft_printf_putchar_fd(fd, dest[i--]);
	return (res);
}
