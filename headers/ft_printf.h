/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:13:47 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:40:40 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <aio.h>

# include "libft.h"

int	ft_printf(const char *format, ...);

int	ft_printf_putchar(char c);
int	ft_printf_putstr(char *str);
int	ft_printf_putptr(void *ptr);
int	ft_printf_puthexa(unsigned long nmb, char format);
int	ft_printf_putnumber(int nmb);
int	ft_printf_putunsigned(unsigned int nmb);
int	ft_printf_puterror(char *str);
int	ft_printf_putdarray(char **darray);

int	ft_dprintf(int fd, const char *format, ...);

int	ft_printf_putchar_fd(int fd, char c);
int	ft_printf_putstr_fd(int fd, char *str);
int	ft_printf_putptr_fd(int fd, void *ptr);
int	ft_printf_puthexa_fd(int fd, unsigned long nmb, char format);
int	ft_printf_putnumber_fd(int fd, int nmb);
int	ft_printf_putunsigned_fd(int fd, unsigned int nmb);
int	ft_printf_putdarray_fd(int fd, char **darray);

#endif
