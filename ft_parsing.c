/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:14:04 by ataguiro          #+#    #+#             */
/*   Updated: 2016/12/01 11:14:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_is_option(char *s, char *first, int i)
{
	if (!ft_strcmp(s, "--") && i != 1 && !ft_strcmp(first, "--"))
		return (0);
	if (s && ft_strcmp(s, first) && !ft_strcmp(first, "--"))
		return (0);
	if (s && s[0] == '-' && s[1])
		return (1);
	return (0);
}

int		ft_is_in(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_get_option(t_tr *arg, char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (ft_is_in(str[i], "FRatlro1i") || (str[1] == '-' && !str[2]))
		{
			arg->l = (str[i] == 'l' ? 1 : arg->l);
			arg->r_maj = (str[i] == 'R' ? 1 : arg->r_maj);
			arg->a = (str[i] == 'a' ? 1 : arg->a);
			arg->r = (str[i] == 'r' ? 1 : arg->r);
			arg->t = (str[i] == 't' ? 1 : arg->t);
			arg->o = (str[i] == 'o' ? 1 : arg->o);
			arg->one = (str[i] == '1' ? 1 : arg->one);
			arg->one = ((str[i] == 'l' || str[i] == 'o') ? 0 : arg->one);
			arg->i = (str[i] == 'i' ? 1 : arg->i);
			arg->f_maj = (str[i] == 'F' ? 1 : arg->f_maj);
		}
		else
		{
			ft_illegal_option(str[i]);
			return (0);
		}
	}
	return (1);
}

int		ft_get_params(int n, char **argv, t_tr *param, t_list **path)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < n)
	{
		(!ft_is_option(argv[i + 1], argv[i], i + 1)) ? flag = 0 : 0;
		if (flag == 1 && !ft_get_option(param, argv[i + 1]))
			return (0);
		else if (flag == 0)
			ft_lstpushback(path, argv[i + 1], ft_strlen(argv[i + 1]));
	}
	return (1);
}
