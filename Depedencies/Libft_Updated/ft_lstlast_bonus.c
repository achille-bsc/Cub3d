/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:23:46 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:46:23 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
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
// 		test = ft_lstlast(test);
// 		ft_lstprint(test);
// 	}
// 	return (0);
// }
