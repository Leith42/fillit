/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:00:10 by aazri             #+#    #+#             */
/*   Updated: 2016/12/05 19:23:09 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri *tetri_new_position(t_tetri *piece, size_t x, size_t y)
{
	size_t i;
	int min_piece_x;
	int min_piece_y;

	i = 0;
	while (i != 4)
	{
		if (piece->x[i] < min_piece_x || i == 0)
			min_piece_x = piece->x[i];
		if (piece->y[i] < min_piece_y || i == 0)
			min_piece_y = piece->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		piece->x[i] = piece->x[i] - min_piece_x + x;
		piece->y[i] = piece->y[i] - min_piece_y + y;
		i++;
	}
	return (piece);
}

t_tetri	*tetri_initial_position(t_tetri *piece, char **tab) // Stock la position initiale de chaques tetrominos dans leurs maillons respectifs
{
	size_t	i;
	size_t	x;
	size_t	y;

	y = 0;
	i = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == '#')
			{
				piece->x[i] = x;
				piece->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (piece);
}

t_tetri	*stock_pos(t_tetri *piece)
{
	t_tetri	*start;

	start = piece;
	while (piece->next)
	{
		piece = tetri_initial_position(piece, ft_strsplit(piece->str, '\n'));
		free(piece->str);
		piece = piece->next;
	}
	return (start);
}
