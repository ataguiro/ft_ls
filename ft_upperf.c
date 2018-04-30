/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 01:48:10 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 15:39:20 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_upperf(t_hard *new, t_tr arg, int *a)
{
	if (arg.f_maj)
	{
		if (S_ISLNK(new->st_mode))
			ft_putchar('@');
		else if (S_ISDIR(new->st_mode))
			ft_putchar('/');
		else if (S_ISFIFO(new->st_mode))
			ft_putchar('|');
		else if (new->st_mode & S_IXUSR || new->st_mode & S_IXGRP ||
		new->st_mode & S_IXOTH)
			ft_putchar('*');
		(*a) += 0;
	}
}

void	ft_upperf_none(t_hard *new, t_tr arg)
{
	if (arg.f_maj)
	{
		if (S_ISLNK(new->st_mode))
			ft_putchar('@');
		else if (S_ISDIR(new->st_mode))
			ft_putchar('/');
		else if (S_ISFIFO(new->st_mode))
			ft_putchar('|');
		else if (new->st_mode & S_IXUSR || new->st_mode & S_IXGRP ||
		new->st_mode & S_IXOTH)
			ft_putchar('*');
	}
}

void	ft_display_rmaj(t_hard *info, t_tr arg)
{
	t_hard	*cpy;

	cpy = info;
	while (cpy)
	{
		if (cpy->file && cpy->path && S_ISDIR(cpy->st_mode) &&
		ft_strcmp(".", cpy->file) && ft_strcmp("..", cpy->file) &&
		(arg.a || cpy->file[0] != '.'))
			ft_executer(arg, cpy->path);
		cpy = cpy->next;
	}
}

void	ft_executer(t_tr arg, char *path)
{
	t_hard			*info;
	struct dirent	*lu;
	DIR				*dir;

	info = NULL;
	if (path)
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putendl(":");
	}
	if ((dir = opendir(path)))
	{
		while ((lu = readdir(dir)))
			ft_getinfo(lu->d_name, &info, ft_strjoin(path, "/"), arg);
		closedir(dir);
		if (info)
			ft_totalfor(info, arg);
		info = NULL;
		return ;
	}
	ft_perror(path);
}

void	ft_totalfor(t_hard *info, t_tr arg)
{
	if ((arg.l || arg.o) && !arg.one)
	{
		ft_putstr("total ");
		ft_punbrendl(ft_total(info, arg));
	}
	ft_display(NULL, info, arg, 1);
}
