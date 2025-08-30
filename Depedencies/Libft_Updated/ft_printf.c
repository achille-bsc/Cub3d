/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:49:56 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/14 02:24:00 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	selec(const char c, va_list args)
{
	int	returned;

	returned = 0;
	if (c == 'c')
		returned = ft_printf_putchar((char)va_arg(args, int));
	else if (c == 's')
		returned = ft_printf_putstr(va_arg(args, char *));
	else if (c == 'D')
		returned = ft_printf_putdarray(va_arg(args, char **));
	else if (c == 'e')
		returned = ft_printf_puterror(va_arg(args, char *));
	else if (c == 'p')
		returned = ft_printf_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		returned = ft_printf_putnumber(va_arg(args, int));
	else if (c == 'u')
		returned = ft_printf_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		returned = ft_printf_puthexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		returned = ft_printf_putchar('%');
	return (returned);
}

int	ft_printf(const char *format, ...)
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
				returned += selec(format[i], args);
			else
				return (ft_printf_putstr("Erreur : '%' seul"), returned);
		}
		else
			returned += ft_printf_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (returned);
}
