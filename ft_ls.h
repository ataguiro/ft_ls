/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:49:03 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 16:00:32 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <fcntl.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_lspace
{
	int					first;
	int					echo;
	int					staff;
	int					longn;
	int					min;
	int					maj;
	int					id;
	int					max;
}				t_lspace;

typedef struct	s_tr
{
	int			l;
	int			a;
	int			r_maj;
	int			t;
	int			r;
	int			o;
	int			one;
	int			i;
	int			f_maj;
}				t_tr;

typedef struct	s_hard
{
	int				i;
	int				row;
	int				col;
	acl_t			acl;
	ssize_t			xattr;
	ino_t			st_ino;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	off_t			st_size;
	gid_t			st_gid;
	quad_t			st_blocks;
	dev_t			st_rdev;
	char			*file;
	char			*path;
	char			*clear_date;
	struct s_hard	*next;
}				t_hard;

void			ft_totalfor(t_hard *info, t_tr arg);
void			ft_executer(t_tr arg, char *path);
void			ft_display_rmaj(t_hard *info, t_tr arg);
void			ft_sort_index(t_hard **info, t_tr arg);
void			ft_upperf_none(t_hard *new, t_tr arg);
void			ft_manage_col(t_hard *info, t_lspace spaces, int **gr);
void			ft_prepare2(t_hard *fold, t_tr arg, int dir, t_hard *tmp);
void			ft_getlspacesid(t_hard *info, t_lspace *spaces, t_tr arg);
void			ft_writeattr(t_hard *new);
void			ft_getattr(t_hard **new);
void			ft_upperf(t_hard *info, t_tr arg, int *a);
void			ft_easy_write(t_hard *info, t_lspace spaces, t_tr arg);
void			ft_list_reversen(t_list **begin_list);
void			ft_time_sortn(t_list **hard);
void			ft_add_disp(t_hard *info, t_tr arg, t_lspace spaces, int *gr);
void			ft_colors(t_hard *info);
int				ft_lstsizehard(t_hard *lst, t_tr arg);
void			ft_manage_date(t_hard *info);
void			ft_manage_special(t_hard *info, t_lspace spaces, int flag);
void			ft_manage_link(t_hard *info, t_tr arg);
int				ft_getlspacesmin(t_hard *info, t_tr arg);
int				ft_getlspacesmaj(t_hard *info, t_tr arg);
void			ft_writemm(t_hard *info, t_lspace spaces);
int				ft_total(t_hard *info, t_tr arg);
void			ft_illegal_option(char c);
void			ft_list_reverse(t_hard **begin_list);
void			ft_time_sort(t_hard **hard, t_tr arg);
void			ft_getlspacesfirst(t_hard *info, t_lspace *spaces, t_tr arg);
void			ft_getlspacesecho(t_hard *info, t_lspace *spaces, t_tr arg);
void			ft_getlspacesstaff(t_hard *info, t_lspace *spaces, t_tr arg);
void			ft_getlspaceslongn(t_hard *info, t_lspace *spaces, t_tr arg);
void			ft_putspaces(t_lspace spaces, t_hard *info, int number);
void			ft_writemode(t_hard *new);
void			ft_display_l(t_hard *info, t_tr arg, t_hard *fold);
void			ft_executel(t_hard *info, t_lspace spaces, t_tr arg);
int				ft_getspaces(t_hard *info, t_tr arg);
void			ft_bigswap(t_hard **a, t_hard **b);
void			ft_swaphard(t_hard **hard, t_hard *cpy);
void			ft_hard_sort(t_hard **hard);
void			ft_perror(char *s);
void			ft_prepare_hard(t_hard *fold, t_tr arg, int dir);
void			ft_prepare_normal(t_hard *fold, t_tr arg, int dir);
void			ft_swap(t_list **a, t_list **b);
void			ft_list_sort(t_list **begin_list);
void			ft_prepare(t_hard *fold, t_tr arg, int dir);
void			ft_display_other(t_hard *info, t_tr arg);
void			ft_display(t_hard *fold, t_hard *info, t_tr arg, int dir);
t_hard			*ft_recover(char *file, char *path);
void			ft_getinfo(char *file, t_hard **info, char *path, t_tr arg);
int				ft_get_params(int n, char **argv, t_tr *param, t_list **path);
int				ft_get_option(t_tr *arg, char *str);
int				ft_is_in(char c, const char *str);
int				ft_is_option(char *s, char *first, int i);
void			ft_manage(t_tr arg, t_list *path, int dir);
void			ft_rep(t_tr arg, t_list *rep, int dir);
void			ft_fichier(t_tr arg, t_list *fichier);

#endif
