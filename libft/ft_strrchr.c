/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:16:33 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/15 23:55:39 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	out = NULL;
	while (*s)
	{
		if (*s == (char)c)
			out = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	return (out);
}
