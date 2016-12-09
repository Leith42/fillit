/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/08 16:51:17 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char const *argv[])
{
	t_tetri *piece;
	char *read;
	char **tab = NULL;
	size_t square_size;

	if (argc != 2)
		quit(INVALID);
	read = read_file(open(argv[1], O_RDONLY));
	square_size = ft_sqroot(tetri_counter(read) * 4);
	piece = stock_tetri(read); // Stock chaques tetrominos dans une liste
	piece = stock_pos(piece); // Stock la position (forme) des tetrominos dans leurs listes
	while(!tab)
	{
		tab = fill_empty(tab, square_size); // Rempli la grille de points
		tab = solver(tab, piece, square_size); // Algo de résolution
		square_size++;
	}
	display_tab(tab);
	free_tetrominos(tab, piece);
	return (0);
}
