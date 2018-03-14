/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:42:21 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/07 16:56:01 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strllen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static t_list	*init_lst(t_list **lst, size_t fd)
{
	t_list	*tmp;

	if (!*lst)
		*lst = ft_lstnew("\0", fd);
	tmp = *lst;
	while (tmp->content_size != fd)
	{
		if (!tmp->next)
			tmp->next = ft_lstnew("\0", fd);
		tmp = tmp->next;
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				r;
	char			buffer[BUFF_SIZE + 1];
	char			*c;
	static	t_list	*lst = NULL;
	t_list			*tmp;

	if (fd < 0)
		return (-1);
	tmp = init_lst(&lst, (size_t)fd);
	c = (char *)tmp->content;
	while (!ft_strchr(c, '\n') && (r = read(fd, buffer, BUFF_SIZE)))
	{
		if (r == -1)
			return (-1);
		buffer[r] = '\0';
		if (!(c = ft_strfjoin(&c, buffer)))
			return (-1);
	}
	if (!*c)
		return (0);
	*line = ft_strncpy(ft_strnew(ft_strllen(c) + 1), c, ft_strllen(c));
	tmp->content = ft_strdup((c + ft_strllen(c) + 1));
	free(c);
	return (1);
}
