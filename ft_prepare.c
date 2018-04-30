/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:45:48 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 16:43:58 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstsizehard(t_hard *lst, t_tr arg)
{
	int		size;

	size = 0;
	while (lst)
	{
		if ((arg.a || (lst->file)[0] != '.') || ft_strchr(lst->file, '/'))
			size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_colors(t_hard *info)
{
	if (S_ISDIR(info->st_mode))
		ft_putstr("\x1B[1;36m");
	if ((info->st_mode & S_IXUSR || info->st_mode & S_IXGRP ||
			info->st_mode & S_IXOTH) && S_ISREG(info->st_mode))
		ft_putstr("\033[0;31m");
	if (S_ISLNK(info->st_mode))
		ft_putstr("\033[0;35m");
}

void	ft_prepare2(t_hard *fold, t_tr arg, int dir, t_hard *tmp)
{
	ft_hard_sort(&tmp);
	if (dir)
	{
		ft_putstr(fold->file);
		ft_putendl(":");
	}
	ft_display(fold, tmp, arg, 1);
}
