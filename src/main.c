/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/17 17:41:03 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char const *argv[])
{
	t_tetri	*piece;
	char	*read;
	char	**tab;
	size_t	square_size;

	tab = NULL;
	if (argc != 2)
		quit(DISPLAY_USAGE);
	read = read_file(open(argv[1], O_RDONLY));
	square_size = ft_sqroot(tetri_counter(read) * 4);
	piece = stock_tetri(read);
	piece = stock_pos(piece);
	while (!tab)
	{
		tab = solver(fill_empty(tab, square_size), piece, square_size);
		square_size++;
	}
	display_tab(tab);
	free_tetrominos(tab, piece, read);
	return (0);
}
