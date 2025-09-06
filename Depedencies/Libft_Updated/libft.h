/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:10:32 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/09/06 18:58:43 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define ERR_MALLOC "\033[1;91mError: Malloc error\n\033[0m"

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

/* ********************************************* */

/* ********************************************* */
/*                BOOL CONDITIONS                */
/* ********************************************* */

bool				ft_isatoiable(char c);
bool				ft_isalpha(int c);
bool				ft_isdigit(int c);
bool				ft_isalnum(int c);
bool				ft_isascii(int c);
bool				ft_isprint(int c);
bool				ft_isnum(char s);

/* ********************************************* */
/*                MEMORY MANAGEMENT              */
/* ********************************************* */

/*                 MEMORY MODIFIER               */

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t size);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_mem_reset(void **mem);

/*                 MEMORY RELEASE               */

void				ft_str_reset(char **sent);
void				ft_freeall(char *format, ...);
void				ft_freedarray(char **darray);
void				ft_darray_reset(char ***darray);

/* ********************************************* */
/*                     STRINGS                   */
/* ********************************************* */

/*                     BASICS                    */

size_t				ft_strcpy(char *dst, const char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

char				*ft_strcat(char *dst, char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strstr(const char *sent, const char *target);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/*                    ADVANCED                   */

char				*ft_strdup(const char *s);
char				*ft_strfdup(char *sent);
char				*ft_strndup(char *sent, int size);
char				*ft_strnfdup(char *src, int size);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdjoin(char *dest, char *src1, char *src2);
char				*ft_strjoining(char *s1, char const *s2);
char				*ft_strdjoining(char *dest, char *src1, char *src2);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_rmchars(char *str, char c);
void				ft_str_replace(char **dest, char *src);
char				*ft_strn_replace(char *sent, int sizemax);

int					ft_strncmpcat(const char *s1, const char *s2, char *joined,
						size_t n);

/*                     UTILS                     */

size_t				ft_strlen(const char *s);
int					ft_strlen_til_char(char *sent, char c);
int					ft_revstrlen_til_char(char *src, char c);

/* ********************************************* */
/*                     MATRIX                    */
/* ********************************************* */

char				**ft_split(char const *s, char c);
char				**ft_arraydup(char **array);
char				**ft_addtoda(char **darray, char *str);
int					ft_darraylen(char **array);

/* ********************************************* */
/*                   CONVERSION                  */
/* ********************************************* */

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
unsigned long		ft_atoul(const char *nptr);

char				*ft_itoa(int n);
char				*ft_ultoa(unsigned long n);
char				*ft_doubtoa(double numb);

long				*ft_datola(char **darray, int args);
int					*ft_datoia(char **darray, int args);

/* ********************************************* */
/*                       I/O                     */
/* ********************************************* */

void				ft_dup_close(int fd_src, int fd_dest);
void				ft_putendl_fd(char *s, int fd);
void				ft_close(int *fd);
char				*get_all_file(int fd);
char				*get_n_close(int fd);

/* ********************************************* */
/*                      LISTS                    */
/* ********************************************* */

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *list, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ********************************************* */

#endif
