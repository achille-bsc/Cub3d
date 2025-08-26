/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:08:06 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:43:09 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}

// #include <stdio.h>

// void	ft_lstprint(t_list *liste)
// {
// 	t_list	*tmp;
// 	char	*s;

// 	tmp = liste;
// 	while (tmp != NULL)
// 	{
// 		s = tmp->content;
// 		printf("%s -> ", s);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// }

// void	ft_repbyx(void *s)
// {
// 	char	*sx;

// 	sx = s;
// 	sx[0] = 'X';
// }

// int	main(int argc, char *argv[])
// {
// 	t_list	*test;

// 	if (argc == 2)
// 	{
// 		test = ft_lstnew(ft_strdup(argv[1]));
// 		ft_lstprint(test);
// 		ft_lstiter(test, ft_repbyx);
// 		ft_lstprint(test);
// 	}
// 	return (0);
// }
