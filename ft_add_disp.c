/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_disp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:27:10 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 14:37:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getlspacesid(t_hard *info, t_lspace *spaces, t_tr arg)
{
	size_t	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
			!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_intlength(info->st_ino);
	while (info && info->next)
	{
		if ((ft_intlength(info->next->st_ino)) > (int)max)
			max = ft_intlength(info->next->st_ino);
		info = info->next;
	}
	spaces->id = (int)max;
}

void	ft_easy_write(t_hard *info, t_lspace spaces, t_tr arg)
{
	if (arg.i)
	{
		ft_putspaces(spaces, info, 5);
		ft_putnbr(info->st_ino);
		ft_putchar(' ');
	}
	ft_writemode(info);
	ft_putspaces(spaces, info, 1);
	ft_putstr(ft_strjoin(ft_itoa(info->st_nlink), " "));
	ft_putstr(getpwuid(info->st_uid)->pw_name);
	ft_putspaces(spaces, info, 2);
}

void	ft_add_disp(t_hard *info, t_tr arg, t_lspace spaces, int *gr)
{
	int		a;

	a = 0;
	if (arg.i)
	{
		ft_putspaces(spaces, info, 5);
		ft_putnbr(info->st_ino);
		ft_putchar(' ');
	}
	ft_colors(info);
	ft_putstr(info->file);
	ft_putstr("\x1B[0m");
	ft_upperf(info, arg, &a);
	if (!arg.one && (ft_lstsizehard(info, arg) > 1))
		while ((size_t)a++ < (spaces.max - ft_strlen(info->file) + 1))
			ft_putchar(' ');
	if (!arg.one)
		ft_manage_col(info, spaces, &gr);
	else if (!(!arg.one && (ft_lstsizehard(info, arg) > 1)) &&
	(info->next && (info->next->file)[0] != 0))
		ft_putchar('\n');
}

void	ft_manage_col(t_hard *info, t_lspace spaces, int **gr)
{
	if (**gr == 0)
	{
		if (((info->i * (spaces.max + 1)) * 2) > info->col
		&& info->next)
		{
			**gr = info->i + 1;
			ft_putchar('\n');
			return ;
		}
	}
	else if (info->i > **gr)
	{
		if (info->next && ((info->i + 1) % **gr == 0) &&
		info)
			ft_putchar('\n');
	}
}
