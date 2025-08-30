/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnumber.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 04:28:27 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:04:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnumber(int nmb)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (nmb < 0)
	{
		res += ft_printf_putchar('-');
		sign = -1;
	}
	if (nmb / 10)
		res += ft_printf_putnumber((nmb / 10) * sign);
	res += ft_printf_putchar((nmb % 10) * sign + '0');
	return (res);
}

int	ft_printf_putnumber_fd(int fd, int nmb)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (nmb < 0)
	{
		res += ft_printf_putchar_fd(fd, '-');
		sign = -1;
	}
	if (nmb / 10)
		res += ft_printf_putnumber_fd(fd, (nmb / 10) * sign);
	res += ft_printf_putchar_fd(fd, (nmb % 10) * sign + '0');
	return (res);
}
