/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puterror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:47:09 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/05/20 21:31:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_puterror(char *str)
{
	int	ret;

	if (str == NULL)
		return (write(2, "(null)", 6));
	ret = write(2, str, ft_strlen(str));
	ret = write(2, "\n", 1);
	return (ret);
}
