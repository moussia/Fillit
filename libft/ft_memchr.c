/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:12:19 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/15 23:51:17 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
