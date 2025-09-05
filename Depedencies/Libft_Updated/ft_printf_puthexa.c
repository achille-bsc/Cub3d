/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:35:17 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 04:03:40 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_puthexa(unsigned long nmb, char format)
{
	char	*def;
	int		res;

	if (format == 'x')
		def = "0123456789abcdef";
	else
		def = "0123456789ABCDEF";
	res = 0;
	if (nmb / 16)
		res += ft_printf_puthexa(nmb / 16, format);
	res += ft_printf_putchar(def[nmb % 16]);
	return (res);
}

int	ft_printf_puthexa_fd(int fd, unsigned long nmb, char format)
{
	char	*def;
	int		res;

	if (format == 'x')
		def = "0123456789abcdef";
	else
		def = "0123456789ABCDEF";
	res = 0;
	if (nmb / 16)
		res += ft_printf_puthexa_fd(fd, nmb / 16, format);
	res += ft_printf_putchar_fd(fd, def[nmb % 16]);
	return (res);
}

static int	ft_numblen(unsigned int enby)
{
	int	len;

	len = 0;
	if (enby == 0)
		return (1);
	while (enby > 0)
	{
		len++;
		enby /= 16;
	}
	return (len);
}

/*
	ft_itoa - Converts an int to a null-terminated decimal string.
	Allocates memory for the string and handles negative numbers.
	Returns NULL on allocation failure.
*/
char	*ft_hextoa(unsigned int n, char format)
{
	char			*buffer;
	char			*def;
	int				i;
	unsigned int	enby;

	if (format == 'X')
		def = "0123456789ABCDEF";
	else
		def = "0123456789abcdef";
	enby = n;
	i = ft_numblen(enby);
	buffer = ft_calloc((i + 1));
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	while (enby > 15)
	{
		buffer[i--] = def[enby % 16];
		enby /= 16;
	}
	buffer[i] = def[enby];
	return (buffer);
}
