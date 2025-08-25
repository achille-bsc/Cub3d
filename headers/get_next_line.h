/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:35:43 by abosc             #+#    #+#             */
/*   Updated: 2025/08/25 23:35:47 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:28:58 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/25 01:26:31 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "libft.h"

typedef struct s_gnl
{
	char			*ctn;
	struct s_gnl	*next;
}					t_gnl;

char	*get_next_line(int fd);
void	read_n_stash(int fd, t_gnl **stash);
int		found_new_line(t_gnl *stash);
void	add_to_stash(t_gnl **stash, char *buffer, int red);
void	extract_line(t_gnl *stash, char **line);
void	ft_count_n_malloc(t_gnl *stash, char **line);
void	clean_stash(t_gnl **stash);
void	free_stash(t_gnl *stash);
t_gnl	*gnl_lstlast(t_gnl *lst);

#endif