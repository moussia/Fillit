/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:37:25 by mmottal           #+#    #+#             */
/*   Updated: 2017/12/21 16:48:53 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_piece(t_carre *c, t_pieces *p)
{
	int		x;
	int		y;

	x = 0;
	while (x < c->taille)
	{
		y = 0;
		while (y < c->taille)
		{
			if (c->carre[x][y] == p->nb)
				c->carre[x][y] = '.';
			y++;
		}
		x++;
	}
}

void		copie(t_carre *c, t_pieces *p, int i, int j)
{
	int		x;
	int		y;
	int		w;

	w = 0;
	x = 0;
	while (!is_in_colon(p, w))
		w++;
	while (x < p->l + 1)
	{
		y = 0;
		while (y < p->h)
		{
			if (p->piece[y][x + w] != '.' && p->piece[y][x + w])
				c->carre[i + y][j + x] = p->piece[y][x + w];
			y++;
		}
		x++;
	}
}

int			backtracking(t_carre *c, t_pieces *p)
{
	int		x;
	int		y;

	x = 0;
	if (!p)
		return (1);
	while (x < c->taille)
	{
		y = 0;
		while (y < c->taille)
		{
			if (verifcopie(p, c, x, y))
			{
				if (backtracking(c, p->next))
					return (1);
				else
					del_piece(c, p);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int			verifcopie(t_pieces *p, t_carre *c, int i, int j)
{
	int		x;
	int		y;
	int		w;

	w = 0;
	if ((p->h > (c->taille - i) || p->l > (c->taille - j)))
		return (0);
	x = 0;
	while (!is_in_colon(p, w))
		w++;
	while (x < p->l + 1)
	{
		y = 0;
		while (y < p->h)
		{
			if (p->piece[y][x + w] != '.' && c->carre[i + y][j + x] != '.'
				&& p->piece[y][x + w])
				return (0);
			y++;
		}
		x++;
	}
	copie(c, p, i, j);
	return (1);
}

char		**remplircarre(t_pieces *b, t_carre *c)
{
	int			i;
	int			j;
	char		nb;
	t_pieces	*tmp;

	i = 0;
	j = 0;
	nb = 'A';
	tmp = b;
	while (tmp)
	{
		tmp->nb = nb;
		tmp = tmp->next;
		nb++;
	}
	while (!(backtracking(c, b)))
		make_square(++c->taille, c);
	return (c->carre);
}
