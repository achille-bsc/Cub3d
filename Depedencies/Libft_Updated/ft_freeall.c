/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:37:20 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/16 02:51:06 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	selec(char c, va_list args)
{
	if (c == 's')
		ft_str_reset(va_arg(args, char **));
	else if (c == 'd')
		ft_darray_reset(va_arg(args, char ***));
	else if (c == 'm')
		ft_mem_reset(va_arg(args, void **));
	else if (c == 'c')
		ft_close(va_arg(args, int *));
	else
		ft_printf("%e", "Error: unreconized format");
}

void	ft_freeall(char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return ;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i++] != '\0')
				selec(format[i], args);
			else
			{
				ft_printf("%e", "Error: incomplete format specifier");
				return ;
			}
		}
		i++;
	}
	va_end (args);
}
