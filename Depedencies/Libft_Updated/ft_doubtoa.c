/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:19:28 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/05 04:52:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numblen(long int enby)
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

static char	*_ft_itoa(int n)
{
	char		*buffer;
	int			i;
	long int	enby;

	enby = (long int)n;
	i = ft_numblen(enby);
	buffer = ft_calloc((i + 1));
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	while (enby > 9)
	{
		buffer[i--] = enby % 10 + '0';
		enby /= 10;
	}
	buffer[i] = enby + '0';
	return (buffer);
}

static bool	ft_hernia(char **res, double *numb)
{
	*res = NULL;
	if (*numb < 0)
	{
		*res = ft_strdup("-");
		if (!*res)
			return (NULL);
		*numb *= -1;
	}
	return (true);
}

char	*ft_doubtoa(double numb)
{
	char	*res;
	char	*tmp;
	double	dec;

	if (!ft_hernia(&res, &numb))
		return (NULL);
	tmp = _ft_itoa(numb);
	if (!tmp)
		return (NULL);
	res = ft_strjoining(res, tmp);
	if (!res)
		return (NULL);
	ft_str_reset(&tmp);
	dec = numb - (int)numb;
	dec *= 100;
	tmp = _ft_itoa(dec);
	if (!tmp)
		return (NULL);
	res = ft_strdjoining(res, ".", tmp);
	if (!res)
		return (NULL);
	ft_str_reset(&tmp);
	return (res);
}
