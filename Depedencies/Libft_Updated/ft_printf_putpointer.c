/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:30:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/21 06:31:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putptr(void *ptr)
{
	if (ptr == NULL)
		return (ft_printf_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_printf_puthexa((unsigned long)ptr, 'x'));
}

int	ft_printf_putptr_fd(int fd, void *ptr)
{
	int	ret;

	if (ptr == NULL)
		return (ft_printf_putstr_fd(fd, "(nil)"));
	ret = write(1, "0x", 2) + ft_printf_puthexa_fd(fd, (unsigned long)ptr, 'x');
	return (ret);
}
