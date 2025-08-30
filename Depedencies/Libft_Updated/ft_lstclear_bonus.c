/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:33:47 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:40:13 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
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

// int	main(int argc, char *argv[])
// {
// 	t_list	*test;

// 	if (argc == 3)
// 	{
// 		test = ft_lstnew(ft_strdup(argv[1]));
// 		ft_lstadd_back(&test, ft_lstnew(ft_strdup(argv[2])));
// 		ft_lstadd_front(&test, ft_lstnew(ft_strdup(argv[0])));
// 		ft_lstprint(test);
// 		ft_lstclear(&test, free);
// 		if (test)
// 			ft_lstprint(test);
// 		else
// 			printf("cleared ;P");
// 	}
// 	return (0);
// }
