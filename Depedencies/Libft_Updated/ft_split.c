/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:38:02 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:05:59 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	cw;
	int	i;

	cw = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cw++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (cw);
}

static void	**ft_free(char **buffer, int count)
{
	while (count > 0)
		free((buffer)[--count]);
	if (buffer != NULL)
		free(buffer);
	return (NULL);
}

static int	ft_split_exec(const char *s, char c, char **buffer)
{
	int		counter;
	int		wcount;
	int		i;

	i = 0;
	wcount = 0;
	while (s[i] != '\0' && wcount < ft_countword(s, c))
	{
		counter = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			while (s[counter + i] != c && s[counter + i] != '\0')
				counter++;
			buffer[wcount] = ft_substr(s, i, counter);
			if (!buffer[wcount])
				return (ft_free(buffer, wcount), -1);
			i = i + counter;
			wcount++;
		}
	}
	return (wcount);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		wcount;

	if (!s)
		return (NULL);
	buffer = ft_calloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	wcount = ft_split_exec(s, c, buffer);
	if (wcount == -1)
		return (NULL);
	buffer[wcount] = NULL;
	return (buffer);
}

// int	main(void)
// {
// 	int		i = 0;
// 	char	s[] = "1264 168 neirst iresntul";
// 	char	**buffer = ft_split(s, ' ');

// 	// printf("%d\n", ft_countword(s, ' '));
// 	while (buffer[i] != NULL)
// 	{
// 		printf("%s\n", buffer[i]);
// 		i++;
// 	}
// 	while (i + 1 > 0)
// 	{
// 		free(buffer[i]);
// 		i--;
// 	}
// 	free(buffer);
// 	return (0);
// }
