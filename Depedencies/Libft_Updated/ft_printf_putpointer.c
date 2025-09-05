/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:30:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 04:14:34 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putptr(void *ptr)
{
	if (!ptr)
		return (ft_printf_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_printf_puthexa((unsigned long)ptr, 'x'));
}

int	ft_printf_putptr_fd(int fd, void *ptr)
{
	int	ret;

	if (!ptr)
		return (ft_printf_putstr_fd(fd, "(nil)"));
	ret = write(1, "0x", 2) + ft_printf_puthexa_fd(fd, (unsigned long)ptr, 'x');
	return (ret);
}

char	*ft_ptrtoa(void *ptr)
{
	char	*tmp;
	char	*ret;

	if (!ptr)
		return (ft_strdup("(nil)"));
	tmp = ft_hextoa((unsigned long)ptr, 'x');
	ret = ft_strjoin("0x", tmp);
	ft_str_reset(&tmp);
	return (ret);
}
