/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:59:22 by asuissa           #+#    #+#             */
/*   Updated: 2017/11/20 22:55:02 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if ((dst < (src + len)) && (src < dst))
	{
		while (len)
		{
			tmp1[len - 1] = tmp2[len - 1];
			len--;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
