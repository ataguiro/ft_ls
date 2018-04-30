/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:26:54 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/30 17:02:45 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list_sort(t_list **list)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (ft_strcmp(a->content, b->content) > 0)
				ft_swap(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_swapcontent(t_list **src, t_list *cpy)
{
	(*src)->content = cpy->content;
	(*src)->content_size = cpy->content_size;
}

void	ft_swap(t_list **a, t_list **b)
{
	t_list	tmp;

	tmp = **a;
	ft_swapcontent(a, *b);
	ft_swapcontent(b, &tmp);
}

void	ft_list_reverse(t_hard **begin_list)
{
	t_hard	*list;
	t_hard	*tmp;
	t_hard	*tmp2;

	tmp = NULL;
	list = *begin_list;
	if (!list || !(list->next))
		return ;
	tmp = list->next;
	tmp2 = tmp->next;
	list->next = NULL;
	tmp->next = list;
	while (tmp2)
	{
		list = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
		tmp->next = list;
	}
	*begin_list = tmp;
}

void	ft_sort_index(t_hard **info, t_tr arg)
{
	t_hard	*tmp;
	int		i;

	i = 0;
	tmp = *info;
	while (tmp)
	{
		if ((arg.a || (tmp->file)[0] != '.') ||
		ft_strchr(tmp->file, '/'))
		{
			tmp->i = i;
			i++;
		}
		tmp = tmp->next;
	}
}
