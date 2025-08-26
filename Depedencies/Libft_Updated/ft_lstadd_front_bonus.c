/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:55:22 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:38:33 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// void	ft_lstprint(t_list *liste)
// {
// 	t_list	*tmp;

// 	tmp = liste;
// 	while (tmp != NULL)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
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
// 		ft_lstadd_front(&test, ft_lstnew(ft_strdup(argv[2])));
// 		ft_lstprint(test);
// 	}
// 	return (0);
// }
