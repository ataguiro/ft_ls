/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:47:20 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 15:09:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_other(t_hard *info, t_tr arg)
{
	t_hard		*new;
	t_lspace	spaces;
	static int	gr = 0;

	new = info;
	ft_getlspacesid(info, &spaces, arg);
	spaces.max = ft_getspaces(new, arg);
	while (info)
	{
		if ((arg.a || (info->file)[0] != '.') ||
		ft_strchr(info->file, '/'))
			ft_add_disp(info, arg, spaces, &gr);
		new = info;
		info = info->next;
	}
	gr = 0;
	((arg.a || (new->file)[0] != '.') || ft_strchr(new->file, '/')) ||
	(new->file[0] == '.' && (arg.t || arg.r)) ? ft_putchar('\n') : NULL;
}

void	ft_getlspaceslongn(t_hard *info, t_lspace *spaces, t_tr arg)
{
	int	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
	!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_intlength(info->st_size);
	while (info && info->next)
	{
		if (arg.a || (info->file[0]) != '.' || ft_strchr(info->file, '/'))
			if (ft_intlength(info->next->st_size) > max)
				max = ft_intlength(info->next->st_size);
		info = info->next;
	}
	spaces->longn = max;
}

void	ft_executel(t_hard *info, t_lspace spaces, t_tr arg)
{
	static int	flag = 0;

	ft_easy_write(info, spaces, arg);
	if (!arg.o)
	{
		ft_putchar(' ');
		ft_putstr(getgrgid(info->st_gid)->gr_name);
		ft_putspaces(spaces, info, 3);
	}
	ft_manage_special(info, spaces, flag);
	if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
		ft_writemm(info, spaces);
	if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
		flag = 1;
	else
	{
		ft_putspaces(spaces, info, 4);
		ft_putnbr(info->st_size);
	}
	ft_putchar(' ');
	ft_manage_date(info);
	ft_manage_link(info, arg);
}

void	ft_display_l(t_hard *info, t_tr arg, t_hard *fold)
{
	t_hard		*new;
	t_lspace	spaces;
	int			x;

	x = ft_total(info, arg);
	new = info;
	ft_getlspacesfirst(info, &spaces, arg);
	ft_getlspacesecho(info, &spaces, arg);
	if (!arg.o)
		ft_getlspacesstaff(info, &spaces, arg);
	spaces.min = ft_getlspacesmin(info, arg);
	spaces.maj = ft_getlspacesmaj(info, arg);
	ft_getlspaceslongn(info, &spaces, arg);
	ft_getlspacesid(info, &spaces, arg);
	if (fold && (arg.a || info->next->next) && opendir(fold->path))
	{
		ft_putstr("total ");
		ft_punbrendl(x);
	}
	while (info)
	{
		if ((arg.a || (info->file)[0] != '.') || ft_strchr(info->file, '/'))
			ft_executel(info, spaces, arg);
		info = info->next;
	}
}

void	ft_display(t_hard *fold, t_hard *info, t_tr arg, int dir)
{
	dir = 1;
	if (info)
	{
		ft_hard_sort(&info);
		if (arg.t)
			ft_time_sort(&info, arg);
		if (arg.r)
		{
			ft_list_reverse(&info);
			ft_sort_index(&info, arg);
		}
		if ((!arg.l && !arg.o) || arg.one)
			ft_display_other(info, arg);
		else if ((arg.l || arg.o) && info)
			ft_display_l(info, arg, fold);
		if (arg.r_maj)
			ft_display_rmaj(info, arg);
	}
}
