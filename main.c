/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/05 00:22:31 by aazri            ###   ########.fr       */
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
        quit(2);
    read = read_file(open(argv[1], O_RDONLY));
	square_size = ft_sqroot(tetri_counter(read) * 4);
	piece = stock_tetri(read); // Stock chaques tetrominos dans une liste
    piece = stock_pos(piece); // Stock la position (forme) des tetrominos dans leur listes
	tab = fill_empty(tab, square_size); // Remplis la grille de points
	tab = solver(tab, piece, square_size); // Algo de résolution
	/*while(*tab)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}*/
    return (false);
}
