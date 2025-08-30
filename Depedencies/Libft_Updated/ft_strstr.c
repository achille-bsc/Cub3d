/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:51:56 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/07 17:57:25 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *sent, const char *target)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(target) == 0)
		return ((char *)sent);
	while (sent[i] != '\0')
	{
		j = 0;
		while (sent[i + j] == target[j])
		{
			j++;
			if (target[j] == '\0')
				return ((char *)sent + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*s1 = "AAAAAAAAAAAAA";
// 	// char	*s2 = "lorem";

// 	printf("%s\n", ft_strnstr(s1, s1, 14));
// 	// printf("%s", strnstr(s1, s2, 6));
// 	return (0);
// }
