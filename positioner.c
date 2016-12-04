/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:00:10 by aazri             #+#    #+#             */
/*   Updated: 2016/12/04 22:23:40 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri *tetri_new_position(t_tetri *piece, size_t x, size_t y)
{
	size_t i;
	size_t piece_x;
	size_t piece_y;

	i = 0;
	piece_x = 50;
	piece_y = 50;
	while (i != 4)
	{
		if (piece->x[i] < piece_x)
			piece_x = piece->x[i];
		if (piece->y[i] < piece_y)
			piece_y = piece->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		piece->x[i] = piece->x[i] - piece_x + x;
		piece->y[i] = piece->y[i] - piece_y + y;
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
		piece = piece->next;
	}
	return (start);
}
