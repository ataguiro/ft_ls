/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 22:28:39 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/07 20:05:34 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	k;

	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < len && new)
	{
		new[i] = s[start];
		start++;
		k++;
		i++;
	}
	new[i] = 0;
	new[i + 1] = 0;
	return (new);
}
