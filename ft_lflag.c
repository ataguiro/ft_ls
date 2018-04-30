/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:45:06 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 16:44:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getlspacesmin(t_hard *info, t_tr arg)
{
	int	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
			!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_intlength(minor(info->st_rdev));
	while (info && info->next)
	{
		if (ft_intlength(minor(info->next->st_rdev)) > max)
			max = ft_intlength(minor(info->next->st_rdev));
		info = info->next;
	}
	return (max);
}

int		ft_getlspacesmaj(t_hard *info, t_tr arg)
{
	int	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
			!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_intlength(major(info->st_rdev));
	while (info && info->next)
	{
		if (ft_intlength(major(info->next->st_rdev)) > max)
			max = ft_intlength(major(info->next->st_rdev));
		info = info->next;
	}
	return (max);
}

void	ft_writemm(t_hard *info, t_lspace spaces)
{
	int	min;
	int	maj;
	int	a;

	min = 0;
	maj = 0;
	a = 0;
	min = spaces.min;
	maj = spaces.maj;
	while (a++ < (maj - ft_intlength(major(info->st_rdev)) + 2))
		ft_putchar(' ');
	ft_putnbr(major(info->st_rdev));
	ft_putstr(",");
	a = 0;
	while (a++ < (min - ft_intlength(minor(info->st_rdev)) + 1))
		ft_putchar(' ');
	ft_putnbr(minor(info->st_rdev));
}

void	ft_writemode(t_hard *new)
{
	ft_putchar((S_ISFIFO(new->st_mode)) ? 'p' : 0);
	ft_putchar((S_ISCHR(new->st_mode)) ? 'c' : 0);
	ft_putchar((S_ISDIR(new->st_mode)) ? 'd' : 0);
	ft_putchar((S_ISBLK(new->st_mode)) ? 'b' : 0);
	ft_putchar((S_ISREG(new->st_mode)) ? '-' : 0);
	ft_putchar((S_ISLNK(new->st_mode)) ? 'l' : 0);
	ft_putchar((S_ISSOCK(new->st_mode)) ? 's' : 0);
	ft_putstr((new->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((new->st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((new->st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((new->st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((new->st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((new->st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((new->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((new->st_mode & S_IWOTH) ? "w" : "-");
	if ((new->st_mode & S_ISVTX))
		ft_putstr("t");
	else if ((new->st_mode & S_IXOTH))
		ft_putstr("x");
	else
		ft_putstr("-");
	ft_writeattr(new);
}
