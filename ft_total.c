/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:12:52 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 16:44:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_total(t_hard *info, t_tr arg)
{
	int		total;

	total = 0;
	while (info)
	{
		if (arg.a || (info->file)[0] != '.')
			total += info->st_blocks;
		info = info->next;
	}
	return (total);
}
