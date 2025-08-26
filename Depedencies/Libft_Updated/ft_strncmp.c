/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:15:33 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/08 20:52:05 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1 = "abcdefgh";
// 	char	*s2 = "acdwxyz";

// 	printf("%d\n", ft_strncmp(s1, s2, 2));
// 	return (0);
// }
