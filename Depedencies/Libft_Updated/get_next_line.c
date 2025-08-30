/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:27:44 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/06/06 03:09:26 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_n_stash(int fd, t_gnl **stash)
{
	char	*buffer;
	int		red_ptr;

	red_ptr = 1;
	while (!found_new_line(*stash))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		red_ptr = (int)read(fd, buffer, BUFFER_SIZE);
		if (red_ptr <= 0)
		{
			if ((*stash) && red_ptr < 0)
			{
				free_stash((*stash));
				(*stash) = NULL;
			}
			return (free(buffer));
		}
		buffer[red_ptr] = '\0';
		add_to_stash(stash, buffer, red_ptr);
		free(buffer);
	}
}

void	add_to_stash(t_gnl **stash, char *buffer, int red)
{
	int		i;
	t_gnl	*current;
	t_gnl	*new;

	new = ft_calloc(sizeof(t_gnl));
	if (!new)
		return ;
	new->next = NULL;
	new->ctn = ft_calloc(red + 1);
	if (!new->ctn)
		return (free(new));
	i = -1;
	while (buffer[++i] && i < red)
		new->ctn[i] = buffer[i];
	new->ctn[i] = '\0';
	if (!*stash)
	{
		*stash = new;
		return ;
	}
	current = gnl_lstlast(*stash);
	current->next = new;
}

void	extract_line(t_gnl *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	ft_count_n_malloc(stash, line);
	if (!*line)
		return (free_stash(stash));
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->ctn[i])
		{
			if (stash->ctn[i] == '\n')
			{
				(*line)[j++] = stash->ctn[i];
				break ;
			}
			(*line)[j++] = stash->ctn[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_gnl **stash)
{
	t_gnl	*last;
	t_gnl	*stash_nl;
	int		i;
	int		j;

	stash_nl = ft_calloc(sizeof(t_gnl));
	if (!stash_nl || !stash)
		return ;
	stash_nl->next = NULL;
	last = gnl_lstlast(*stash);
	i = 0;
	while (last->ctn[i] && last->ctn[i] != '\n')
		i++;
	if (last->ctn[i] && last->ctn[i] == '\n')
		i++;
	stash_nl->ctn = ft_calloc(ft_strlen(last->ctn) - i + 1);
	if (!stash_nl->ctn)
		return ;
	j = 0;
	while (last->ctn[i])
		stash_nl->ctn[j++] = last->ctn[i++];
	stash_nl->ctn[j] = '\0';
	free_stash(*stash);
	*stash = stash_nl;
}

char	*get_next_line(int fd)
{
	static t_gnl	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(stash), NULL);
	read_n_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (!line[0])
	{
		free_stash(stash);
		stash = NULL;
		return (free(line), NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line = NULL;

// 	fd = open("read_error.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 	}
// 	return (0);
// }
