/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:10:54 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:41:10 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
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
// 	t_list	*temp;

// 	if (argc == 3)
// 	{
// 		test = ft_lstnew(ft_strdup(argv[1]));
// 		ft_lstadd_back(&test, ft_lstnew(ft_strdup(argv[2])));
// 		ft_lstprint(test);
// 		temp = test->next;
// 		ft_lstdelone(test, free);
// 		test = temp;
// 		ft_lstprint(test);
// 	}
// 	return (0);
// }
