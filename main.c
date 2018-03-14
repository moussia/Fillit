/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 06:47:32 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/21 06:48:48 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		**tab;
	int			nb_l;
	t_carre		carre;
	t_pieces	*piece_box;
	t_pieces	*tmp;

	nb_l = 0;
	if (!(tab = ft_read(argv[1], &nb_l)) || argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	make_square(ft_sqrt(nb_l), &carre);
	piece_box = makepiece(tab, nb_l);
	tmp = piece_box;
	tab = remplircarre(piece_box, &carre);
	ft_print_words_tables(tab);
	return (0);
}
