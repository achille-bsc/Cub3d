/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:13:47 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 04:57:08 by lvan-bre         ###   ########.fr       */
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

# define ERR_FORMAT		"Error: unknown format : %c\n"
# define ERR_NOFORMAT	"Error: no format given\n"

/* THIS IS PRINTF FAMILY */

/* NORMAL FT_PRINTF */

int		ft_printf(const char *format, ...);

int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *str);
int		ft_printf_putptr(void *ptr);
int		ft_printf_puthexa(unsigned long nmb, char format);
int		ft_printf_putnumber(int nmb);
int		ft_printf_putunsigned(unsigned int nmb);
int		ft_printf_puterror(char *str);
int		ft_printf_putdarray(char **darray);

/* FT_DPRINTF TO WRITE IN ANOTHER FD */

int		ft_dprintf(int fd, const char *format, ...);

int		ft_printf_putchar_fd(int fd, char c);
int		ft_printf_putstr_fd(int fd, char *str);
int		ft_printf_putptr_fd(int fd, void *ptr);
int		ft_printf_puthexa_fd(int fd, unsigned long nmb, char format);
int		ft_printf_putnumber_fd(int fd, int nmb);
int		ft_printf_putunsigned_fd(int fd, unsigned int nmb);
int		ft_printf_putdarray_fd(int fd, char **darray);

bool	ft_smprintf(char **dest, char *format, ...);

char	*ft_ctoa(char c);
char	*ft_strmerge(char **darray);
char	*ft_hextoa(unsigned int n, char format);
char	*ft_ptrtoa(void *ptr);
char	*ft_utoa(unsigned int n);

#endif
