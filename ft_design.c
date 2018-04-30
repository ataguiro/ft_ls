/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_design.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:49:47 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 00:20:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_getlspacesfirst(t_hard *info, t_lspace *spaces, t_tr arg)
{
	int	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
	!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_intlength(info->st_nlink);
	while (info && info->next)
	{
		if (arg.a || (info->next->file[0]) != '.' ||
		ft_strchr(info->next->file, '/'))
			if (ft_intlength(info->next->st_nlink) > max)
				max = ft_intlength(info->next->st_nlink);
		info = info->next;
	}
	spaces->first = max;
}

void		ft_getlspacesecho(t_hard *info, t_lspace *spaces, t_tr arg)
{
	size_t	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
	!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_strlen(getpwuid(info->st_uid)->pw_name);
	while (info && info->next)
	{
		if (arg.a || (info->next->file[0]) != '.' ||
		ft_strchr(info->next->file, '/'))
			if ((ft_strlen(getpwuid(info->next->st_uid)->pw_name)) > max)
				max = ft_strlen(getpwuid(info->next->st_uid)->pw_name);
		info = info->next;
	}
	spaces->echo = (int)max;
}

void		ft_getlspacesstaff(t_hard *info, t_lspace *spaces, t_tr arg)
{
	size_t	max;

	while (info && !(arg.a || (info->file)[0] != '.') &&
	!ft_strchr(info->file, '/'))
		info = info->next;
	if (info)
		max = ft_strlen(getgrgid(info->st_gid)->gr_name);
	while (info && info->next)
	{
		if (arg.a || (info->next->file[0]) != '.' ||
		ft_strchr(info->next->file, '/'))
			if ((ft_strlen(getgrgid(info->next->st_gid)->gr_name)) > max)
				max = ft_strlen(getgrgid(info->next->st_gid)->gr_name);
		info = info->next;
	}
	spaces->staff = (int)max;
}

void		ft_putspaces(t_lspace spaces, t_hard *info, int number)
{
	int	a;

	a = 0;
	if (number == 1)
		while (a++ < (spaces.first - ft_intlength(info->st_nlink) + 1))
			ft_putchar(' ');
	if (number == 2)
		while (a++ < (int)(spaces.echo -
					ft_strlen(getpwuid(info->st_uid)->pw_name) + 1))
			ft_putchar(' ');
	if (number == 3)
		while (a++ < (int)(spaces.staff -
					ft_strlen(getgrgid(info->st_gid)->gr_name) + 1))
			ft_putchar(' ');
	if (number == 4)
		while (a++ < (spaces.longn - ft_intlength(info->st_size) + 1))
			ft_putchar(' ');
	if (number == 5)
		while (a++ < (spaces.id - ft_intlength(info->st_ino)))
			ft_putchar(' ');
}

int			ft_getspaces(t_hard *info, t_tr arg)
{
	size_t		max;

	while (info && info->next &&
	!(arg.a || (info->next->file)[0] != '.') &&
	!ft_strchr(info->next->file, '/'))
		info = info->next;
	if (info)
		max = ft_strlen(info->file);
	while (info && info->next)
	{
		if ((arg.a || (info->next->file)[0] != '.'))
			if (ft_strlen(info->next->file) > max)
				max = ft_strlen(info->next->file);
		info = info->next;
	}
	return (max);
}
