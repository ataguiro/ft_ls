/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:40:30 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/09 20:28:55 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(str) - 1;
	if (!str)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!new)
		return (NULL);
	while (str[len])
	{
		new[i] = str[len];
		len--;
		i++;
	}
	new[i] = 0;
	return (new);
}
