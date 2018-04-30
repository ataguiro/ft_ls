/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:31:31 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/09 13:49:33 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_perror(char *s)
{
	ft_putstr("ls: ");
	perror(s);
}

void	ft_illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-FRailort1] [file ...]\n");
}

void	ft_manage_special(t_hard *info, t_lspace spaces, int flag)
{
	int		a;

	a = 0;
	if (flag && !(S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode)))
	{
		while (a++ < (spaces.min + 2))
			ft_putchar(' ');
		a = 0;
		while (a++ < (spaces.maj))
			ft_putchar(' ');
	}
}

void	ft_manage_link(t_hard *info, t_tr arg)
{
	char	buf[1024];
	ssize_t	i;

	i = 0;
	if (S_ISLNK(info->st_mode))
	{
		i = readlink(info->path, buf, 1024);
		buf[i] = 0;
		ft_colors(info);
		ft_putstr(info->file);
		ft_putstr("\x1B[0m");
		ft_upperf_none(info, arg);
		ft_putstr(" -> ");
		ft_putendl(buf);
	}
	else
	{
		ft_colors(info);
		ft_putstr(info->file);
		ft_putstr("\x1B[0m");
		ft_upperf_none(info, arg);
		ft_putchar('\n');
	}
}

void	ft_manage_date(t_hard *info)
{
	time_t	t;
	int		today;

	today = time(&t);
	if ((today - info->date) < 15778800)
		ft_putstr(ft_strjoin(ft_strsub(ctime(&info->date), 4, 12), " "));
	else
	{
		ft_putstr(ft_strsub(ctime(&info->date), 4, 6));
		ft_putchar(' ');
		ft_putstr(ft_strsub(ctime(&info->date), 19, 5));
		ft_putchar(' ');
	}
}
