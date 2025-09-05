/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:01:13 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 04:14:09 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_numblen - Calculates the number of digits in an unsigned long decimal
	number.
	Returns 1 if the number is zero and len otherwise.
*/
static int	ft_numblen(unsigned long enby)
{
	int	len;

	len = 0;
	if (enby == 0)
		return (1);
	while (enby > 0)
	{
		len++;
		enby /= 10;
	}
	return (len);
}

/*
	ft_ultoa - Converts an unsigned long to a null-terminated decimal string and
	Allocates memory for the string and returns its pointer.
	Returns NULL on allocation failure.
*/
char	*ft_ultoa(unsigned long n)
{
	char		*buffer;
	int			i;

	i = ft_numblen(n);
	buffer = ft_calloc((i + 1));
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	while (n > 9)
	{
		buffer[i--] = n % 10 + '0';
		n /= 10;
	}
	buffer[i] = n + '0';
	return (buffer);
}

char	*ft_utoa(unsigned int n)
{
	char		*buffer;
	int			i;

	i = ft_numblen(n);
	buffer = ft_calloc((i + 1));
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	while (n > 9)
	{
		buffer[i--] = n % 10 + '0';
		n /= 10;
	}
	buffer[i] = n + '0';
	return (buffer);
}
