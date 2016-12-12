/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/12 17:14:53 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char const *argv[])
{
	t_tetri	*piece;
	char	*read;
	char	**tab;
	int		sqroot;
	int		tetri_nbr;

	if (argc != 2)
		quit(INVALID_ARGUMENT);
	tab = NULL;
	read = read_file(open(argv[1], O_RDONLY));
	tetri_nbr = tetri_counter(read);
	sqroot = ft_sqroot(tetri_nbr * 4);
	piece = stock_tetri(read, tetri_nbr); // Stock chaques tetrominos dans une liste
	piece = stock_pos(piece); // Stock la position (forme) des tetrominos dans leurs listes
	while (!tab)
	{
		tab = fill_empty(tab, sqroot); // Rempli la grille de points
		tab = solver(tab, piece, sqroot); // Algo de résolution
		sqroot++;
	}
	display_fillit(tab);
	fill_free(tab, piece, read);
	return (0);
}
