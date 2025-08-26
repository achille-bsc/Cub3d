/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:12:05 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:07:11 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr(char *str)
{
	int	ret;

	if (str == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	ret = write(STDOUT_FILENO, str, ft_strlen(str));
	return (ret);
}

int	ft_printf_putstr_fd(int fd, char *str)
{
	int	ret;

	if (str == NULL)
		return (write(fd, "(null)", 6));
	ret = write(fd, str, ft_strlen(str));
	return (ret);
}
