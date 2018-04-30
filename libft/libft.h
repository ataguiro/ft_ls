/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:52:37 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 16:00:49 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) (x < 0) ? -(x) : x

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_infos
{
	int				words;
	char			**new;
	int				t;
	int				i;
}					t_infos;

typedef struct		s_itoa
{
	char			*buff;
	int				i;
	int				negative;
	long long int	nb;
}					t_itoa;

void				ft_lstpushback(t_list **blst, void const *content,
				size_t content_size);
int					get_next_line(int const fd, char **line);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_intlength(long long int n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				**ft_strsplit(char const *s, char c);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrchr(const char *s, int c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_punbrendl(int n);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_strclr(char *s);
char				*ft_strdup(char *src);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
