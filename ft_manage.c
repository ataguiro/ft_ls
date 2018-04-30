/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:45:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/05 13:24:25 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fichier(t_tr arg, t_list *fichier)
{
	t_hard	*info;
	t_list	*cpy;

	info = NULL;
	cpy = fichier;
	arg.a = 1;
	while (cpy)
	{
		ft_getinfo(cpy->content, &info, "", arg);
		cpy = cpy->next;
	}
	if (info)
		ft_display(NULL, info, arg, 0);
}

void	ft_prepare(t_hard *fold, t_tr arg, int dir)
{
	DIR				*yo;
	t_hard			*tmp;
	int				n;
	struct dirent	*lu;

	n = -1;
	tmp = NULL;
	(arg.t) ? ft_time_sort(&fold, arg) : 0;
	(arg.r) ? ft_list_reverse(&fold) : 0;
	(arg.r) ? ft_sort_index(&fold, arg) : 0;
	while (fold)
	{
		yo = opendir(fold->file);
		while ((lu = readdir(yo)))
			ft_getinfo(lu->d_name, &tmp, ft_strjoin(fold->path, "/"), arg);
		closedir(yo);
		if (tmp)
		{
			++n >= 1 ? ft_putchar('\n') : 0;
			ft_prepare2(fold, arg, dir, tmp);
		}
		tmp = NULL;
		fold = fold->next;
	}
}

void	ft_rep(t_tr arg, t_list *rep, int dir)
{
	t_hard	*info;
	t_list	*cpy;

	info = NULL;
	cpy = rep;
	while (cpy)
	{
		ft_getinfo(cpy->content, &info, "", arg);
		cpy = cpy->next;
	}
	ft_prepare(info, arg, dir);
}

void	ft_manage(t_tr arg, t_list *path, int dir)
{
	struct stat	check;
	t_list		*fichier;
	t_list		*rep;
	t_list		*cpy;

	fichier = NULL;
	rep = NULL;
	cpy = path;
	while (cpy)
	{
		if (stat(cpy->content, &check) == 0 && !S_ISDIR(check.st_mode))
			ft_lstpushback(&fichier, cpy->content, cpy->content_size);
		else if (S_ISDIR(check.st_mode) && !(opendir(cpy->content)))
			ft_perror(cpy->content);
		else if (stat(cpy->content, &check) == 0 && S_ISDIR(check.st_mode))
			ft_lstpushback(&rep, cpy->content, cpy->content_size);
		else
			ft_perror(cpy->content);
		cpy = cpy->next;
	}
	fichier ? ft_fichier(arg, fichier) : NULL;
	fichier && rep ? ft_putendl("") : NULL;
	rep ? ft_rep(arg, rep, dir) : NULL;
}
