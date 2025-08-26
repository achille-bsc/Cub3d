/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_til_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:01:40 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/30 19:09:42 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_til_char(char *sent, char c)
{
	int	len;

	len = 0;
	while (sent && sent[len] && sent[len] != c)
		len++;
	return (len);
}
