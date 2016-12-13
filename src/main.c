/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/13 15:22:57 by mmatime          ###   ########.fr       */
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
		quit(INVALID_ARGUMENT);
	read = read_file(open(argv[1], O_RDONLY));
	square_size = ft_sqroot(tetri_counter(read) * 4);
	piece = stock_tetri(read);
	piece = stock_pos(piece);
	while (!tab)
	{
		tab = fill_empty(tab, square_size);
		tab = solver(tab, piece, square_size);
		square_size++;
	}
	display_tab(tab);
	free_tetrominos(tab, piece);
	return (0);
}
