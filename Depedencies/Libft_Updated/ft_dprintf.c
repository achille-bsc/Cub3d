/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:49:56 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:11:58 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	selec(int fd, const char c, va_list args)
{
	int	returned;

	returned = 0;
	if (c == 'c')
		returned = ft_printf_putchar_fd(fd, (char)va_arg(args, int));
	else if (c == 's')
		returned = ft_printf_putstr_fd(fd, va_arg(args, char *));
	else if (c == 'D')
		returned = ft_printf_putdarray_fd(fd, va_arg(args, char **));
	else if (c == 'p')
		returned = ft_printf_putptr_fd(fd, va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		returned = ft_printf_putnumber_fd(fd, va_arg(args, int));
	else if (c == 'u')
		returned = ft_printf_putunsigned_fd(fd, va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		returned = ft_printf_puthexa_fd(fd, va_arg(args, unsigned int), c);
	else if (c == '%')
		returned = ft_printf_putchar_fd(fd, '%');
	return (returned);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		returned;
	int		i;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	returned = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i++] != '\0')
				returned += selec(fd, format[i], args);
			else
				return (ft_printf_putstr_fd(fd, "Erreur : '%' seul"), returned);
		}
		else
			returned += ft_printf_putchar_fd(fd, format[i]);
		i++;
	}
	va_end (args);
	return (returned);
}
