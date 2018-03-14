/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:11:56 by mmottal           #+#    #+#             */
/*   Updated: 2017/12/21 19:12:58 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_read(char *source, int *nb_l)
{
	int		fd;
	int		r;
	char	buff[BUFF_SIZE + 1];
	char	**tetri;

	fd = open(source, O_RDONLY);
	if ((r = read(fd, buff, BUFF_SIZE)) == -1)
		return (NULL);
	buff[r] = '\0';
	if (!verifligne(buff))
		return (NULL);
	if (!verifchar(buff))
		return (NULL);
	if (!(tetri = ft_strsplit(buff, '\n')))
		return (NULL);
	if (!(*nb_l = verifcarre(tetri)))
		return (NULL);
	if (!verifforme(tetri))
		return (NULL);
	if (buff[r - 1] == '\n' && buff[r - 2] == '\n')
		return (NULL);
	return (tetri);
}

int			make_square(int taille, t_carre *c)
{
	int		i;

	i = 0;
	if (!(c->carre = (char **)malloc(sizeof(char *) * taille + 1)))
		return (0);
	c->carre[taille] = 0;
	while (i < taille)
	{
		if (!(c->carre[i] = (char*)malloc(taille + 1)))
			return (0);
		ft_memset(c->carre[i], '.', taille + 1);
		c->carre[i][taille] = '\0';
		i++;
	}
	c->taille = taille;
	return (1);
}

t_pieces	*makepiece(char **tetri, int nb_l)
{
	t_pieces		*piece_box;
	t_init_piece	a;
	t_pieces		*out;

	ft_bzero(&a, sizeof(t_init_piece));
	init_piece(&out);
	piece_box = out;
	while (a.i < nb_l)
	{
		if (!(a.i % 4) && a.i)
		{
			init_piece(&out->next);
			out = out->next;
			a.j = 0;
		}
		if ((a.r = ft_strnchr(tetri[a.i], '.')) != 4)
		{
			out->l = (4 - a.r) > out->l ? (4 - a.r) : out->l;
			out->h++;
			out->piece[a.j] = ft_strdup(tetri[a.i]);
			a.j++;
		}
		a.i++;
	}
	return (piece_box);
}

void		init_piece(t_pieces **p)
{
	t_pieces	*tmp;

	tmp = *p;
	tmp = malloc(sizeof(t_pieces));
	tmp->l = 0;
	tmp->h = 0;
	tmp->piece = (char**)malloc(sizeof(char*) * 5);
	bzero(tmp->piece, sizeof(char**) * 5);
	tmp->next = NULL;
	*p = tmp;
}

int			is_in_colon(t_pieces *p, int i)
{
	int	j;

	j = 0;
	while (j < p->h)
	{
		if (p->piece[j][i] != '.' && p->piece[j][i])
			return (1);
		j++;
	}
	return (0);
}
