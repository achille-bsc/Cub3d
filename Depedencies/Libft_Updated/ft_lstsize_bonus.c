/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:17:30 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/04 14:19:01 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
// 		printf("Size = %i \n", ft_lstsize(test));
// 	}
// 	return (0);
// }
