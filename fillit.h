/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:13 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/21 19:17:28 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_init_piece
{
	int				i;
	int				r;
	int				j;
}					t_init_piece;

typedef struct		s_pieces
{
	char			nb;
	int				l;
	int				h;
	char			**piece;
	struct s_pieces	*next;
}					t_pieces;

typedef struct		s_carre
{
	int				taille;
	char			**carre;
}					t_carre;

typedef struct		s_init_verif
{
	int				j;
	int				i;
	int				c;
	char			lettre;
}					t_init_verif;

char				**remplircarre(t_pieces *b, t_carre *c);
int					make_square(int taille, t_carre *c);
t_pieces			*makepiece(char **tetri, int nb_l);
int					verifcopie(t_pieces *t, t_carre *c, int i, int j);
int					copie_piece(t_pieces *p, t_carre *c, int i, int j);
void				init_piece(t_pieces **p);
void				init_carre(t_carre *carre);
void				del_piece(t_carre *c, t_pieces *p);
void				copie(t_carre *c, t_pieces *p, int i, int j);
int					backtracking(t_carre *c, t_pieces *p);
int					isgood(char **tetri, int i, int j);
int					verifforme(char **tetri);
int					verifcarre(char **tetri);
char				**ft_read(char *source, int *nb_l);
int					verifligne(char *str);
int					is_in_colon(t_pieces *b, int i);
int					verifchar(char *tab);

#endif
