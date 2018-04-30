/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:05:37 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 11:42:39 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_tr	arg;
	t_list	*path;

	arg = (t_tr) {
		.l = 0,
		.a = 0,
		.r_maj = 0,
		.t = 0,
		.r = 0,
		.o = 0,
		.one = 0,
		.i = 0,
		.f_maj = 0,
	};
	path = NULL;
	if (argc > 1 && !ft_get_params(argc - 1, argv, &arg, &path))
		return (1);
	(!path) ? path = ft_lstnew(".", 1) : 0;
	ft_list_sort(&path);
	if (path->next)
		ft_manage(arg, path, 1);
	else
		ft_manage(arg, path, 0);
	return (0);
}
