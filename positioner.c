/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:00:10 by aazri             #+#    #+#             */
/*   Updated: 2016/11/28 15:08:24 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetri_position(t_tetri *piece, char **tab) // Stock la position de chaques tetrominos dans leurs maillons respectifs
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
				printf("x %d | y %d\n", piece->x[i], piece->y[i]);
				i++;
			}
			x++;
		}
		y++;
	}
	return (piece);
}

t_tetri	*split(t_tetri *piece)
{
	t_tetri	*tmp;

	tmp = piece;
	while (piece->next)
	{
		piece = tetri_position(piece, ft_strsplit(piece->str, '\n'));
		piece = piece->next;
	}
	return (tmp);
}
