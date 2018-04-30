/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:57:55 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 16:27:13 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getinfo(char *file, t_hard **info, char *path, t_tr arg)
{
	t_hard	*cpy;

	cpy = *info;
	if (!file)
		return ;
	if (!cpy)
		*info = ft_recover(file, path);
	else
	{
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = ft_recover(file, path);
		if (cpy && ((arg.a || (cpy->file)[0] != '.') ||
			ft_strchr(cpy->file, '/')))
			cpy->next->i = ft_lstsizehard(*info, arg) - 1;
	}
}

t_hard	*ft_recover(char *file, char *path)
{
	t_hard			*new;
	struct stat		info;
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	new = (t_hard *)malloc(sizeof(t_hard));
	new->row = w.ws_row;
	new->col = w.ws_col;
	new->file = ft_strdup(file);
	new->path = ft_strjoin(path, file);
	lstat(new->path, &info);
	new->st_ino = info.st_ino;
	new->st_mode = info.st_mode;
	new->st_nlink = info.st_nlink;
	new->st_uid = info.st_uid;
	new->st_gid = info.st_gid;
	new->st_size = info.st_size;
	new->st_blocks = info.st_blocks;
	new->date = info.st_mtime;
	new->st_rdev = info.st_rdev;
	ft_getattr(&new);
	new->next = NULL;
	return (new);
}

void	ft_getattr(t_hard **new)
{
	acl_t		acl;
	acl_entry_t	d;
	ssize_t		xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np((*new)->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &d) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr((*new)->path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	(*new)->xattr = xattr;
	(*new)->acl = acl;
}

void	ft_writeattr(t_hard *new)
{
	if (new->xattr > 0)
		ft_putchar('@');
	else if (new->acl != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
}
