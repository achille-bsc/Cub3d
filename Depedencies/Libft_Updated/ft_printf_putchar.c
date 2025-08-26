/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:49:07 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:24:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_putchar_fd( int fd, char c)
{
	return (write(fd, &c, 1));
}
