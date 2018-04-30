/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:13:21 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 16:23:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time_sort(t_hard **hard, t_tr arg)
{
	t_hard	*a;
	t_hard	*b;
	int		i;

	a = *hard;
	i = 0;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->date < b->date)
				ft_bigswap(&a, &b);
			else if (ft_strcmp(a->file, b->file) > 0)
				ft_bigswap(&a, &b);
			b = b->next;
		}
		if ((arg.a || (a->file)[0] != '.') || ft_strchr(a->file, '/'))
		{
			a->i = i;
			i++;
		}
		a = a->next;
	}
}

void	ft_hard_sort(t_hard **hard)
{
	t_hard *a;
	t_hard *b;

	a = *hard;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (ft_strcmp(a->file, b->file) > 0)
				ft_bigswap(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_swaphard(t_hard **hard, t_hard *cpy)
{
	(*hard)->row = cpy->row;
	(*hard)->col = cpy->col;
	(*hard)->acl = cpy->acl;
	(*hard)->xattr = cpy->xattr;
	(*hard)->st_ino = cpy->st_ino;
	(*hard)->date = cpy->date;
	(*hard)->st_mode = cpy->st_mode;
	(*hard)->st_nlink = cpy->st_nlink;
	(*hard)->st_uid = cpy->st_uid;
	(*hard)->st_size = cpy->st_size;
	(*hard)->st_gid = cpy->st_gid;
	(*hard)->st_blocks = cpy->st_blocks;
	(*hard)->st_rdev = cpy->st_rdev;
	(*hard)->file = cpy->file;
	(*hard)->path = cpy->path;
}

void	ft_bigswap(t_hard **a, t_hard **b)
{
	t_hard	tmp;

	tmp = **a;
	ft_swaphard(a, *b);
	ft_swaphard(b, &tmp);
}
