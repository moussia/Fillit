/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:00:59 by mmottal           #+#    #+#             */
/*   Updated: 2017/12/21 19:37:51 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verifligne(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n' || !str[i + 1])
			{
				if (count != 3)
					return (0);
				count = 0;
				i++;
			}
			else
				count++;
		}
		i++;
	}
	return (1);
}

int		verifcarre(char **tetri)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (tetri[i])
	{
		if (ft_strlen(tetri[i]) != 4)
			return (0);
		count += ft_strnchr(tetri[i], '#');
		if (!((i + 1) % 4) && count != 4)
			return (0);
		else if ((!((i + 1) % 4)))
			count = 0;
		i++;
	}
	if (i > (105) || ((i) % 4))
		return (0);
	return (i);
}

int		isgood(char **tetri, int i, int j)
{
	int	test;

	test = 0;
	if (tetri[i][j + 1] != '.' && tetri[i][j + 1])
		test++;
	if (tetri[i + 1] && tetri[i + 1][j] != '.' && tetri[i + 1][j])
		test++;
	if (i && tetri[i - 1][j] != '.')
		test++;
	if (j && tetri[i][j - 1] != '.')
		test++;
	return (test);
}

int		verifforme(char **tetri)
{
	t_init_verif	a;

	ft_bzero(&a, sizeof(a));
	a.lettre = 'A';
	while (tetri[a.i])
	{
		a.j = 0;
		while (a.j < 4)
		{
			if (tetri[a.i][a.j] == '#' && !(a.c += isgood(tetri, a.i, a.j)))
				return (0);
			else if (tetri[a.i][a.j] == '#')
				tetri[a.i][a.j] = a.lettre;
			a.j++;
		}
		a.i++;
		!(a.i % 4) ? a.lettre++ : a.lettre;
		if (!(a.i % 4) && a.c < 6)
			return (0);
		else if (!(a.i % 4))
			a.c = 0;
	}
	return (1);
}

int		verifchar(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != '.' && tab[i] != '#' && tab[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
