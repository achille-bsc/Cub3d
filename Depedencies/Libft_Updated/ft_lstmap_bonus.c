/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:40:05 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:47:39 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buffer;
	t_list	*nlst;

	nlst = NULL;
	while (lst)
	{
		buffer = ft_lstnew(NULL);
		if (buffer == NULL)
		{
			ft_lstclear(&buffer, del);
			break ;
		}
		buffer->content = f(lst->content);
		ft_lstadd_back(&nlst, buffer);
		lst = lst->next;
	}
	return (nlst);
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

// void	*ft_repbyx(void *s)
// {
// 	char	*sx;

// 	sx = s;
// 	sx[0] = 'X';
// 	return (s);
// }

// int	main(int argc, char *argv[])
// {
// 	t_list	*test;
// 	t_list	*mapitest;

// 	if (argc == 2)
// 	{
// 		test = ft_lstnew(ft_strdup(argv[1]));
// 		ft_lstprint(test);
// 		mapitest = ft_lstmap(test, ft_repbyx, free);
// 		ft_lstprint(mapitest);
// 	}
// 	return (0);
// }
