/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 02:04:36 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 05:18:43 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	get_str(char **dest, char *src, int *i)
{
	char	*tmp;
	int		size;

	size = ft_strlen_til_char(src + *i, '%');
	tmp = ft_strndup(src + *i, size);
	if (!tmp)
		return (false);
	*i += size;
	*dest = ft_strjoining(*dest, tmp);
	if (!*dest)
		return (false);
	ft_str_reset(&tmp);
	return (true);
}

static char	*selec(const char c, va_list args)
{
	if (c == 'c')
		return (ft_ctoa((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_strdup(va_arg(args, char *)));
	else if (c == 'D')
		return (ft_strmerge(va_arg(args, char **)));
	else if (c == 'p')
		return (ft_ptrtoa(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hextoa(va_arg(args, unsigned int), c));
	else if (c == 'f')
		return (ft_doubtoa(va_arg(args, double)));
	else if (c == '%')
		return (ft_ctoa('%'));
	else
		return (ft_dprintf(STDERR_FILENO, ERR_FORMAT, c), NULL);
}

static bool	do_selec(char **dest, char src, va_list args)
{
	char	*tmp;

	tmp = selec(src, args);
	if (!tmp)
		return (false);
	*dest = ft_strjoining(*dest, tmp);
	if (!*dest)
		return (false);
	ft_str_reset(&tmp);
	return (true);
}

static bool	main_loop(char **dest, char *src, va_list args)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] != '%')
		{
			if (!get_str(dest, src, &i))
				return (false);
		}
		else
		{
			if (src[++i])
			{
				if (!do_selec(dest, src[i++], args))
					return (false);
			}
		}
	}
	return (true);
}

bool	ft_smprintf(char **dest, char *format, ...)
{
	va_list	args;

	if (!format)
		return (ft_dprintf(STDERR_FILENO, ERR_NOFORMAT), false);
	if (!*dest)
	{
		*dest = ft_calloc(sizeof(char));
		if (!*dest)
			return (false);
	}
	va_start(args, format);
	if (!main_loop(dest, format, args))
		return (false);
	va_end (args);
	return (true);
}
