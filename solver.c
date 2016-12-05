/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:14:00 by aazri             #+#    #+#             */
/*   Updated: 2016/12/05 19:34:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**retry(char **tab, char letter, int sqrsize) // Remplace le tetromino par des points
{
	size_t x;
	size_t y;

	y = 0;
	while (y < sqrsize)
	{
		x = 0;
		while(x < sqrsize)
		{
			if (tab[y][x] == letter)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char	**solver(char **tab, t_tetri *piece, int sqrsize) // Moteur de l'algo en récursif
{
	size_t x;
	size_t y;
	char **tmp;

	if (!piece->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while(y < sqrsize)
	{
		x = 0;
		while(x < sqrsize)
		{
			piece = tetri_new_position(piece, x, y);
			if (position_checker(tab, piece, sqrsize))
			{
				tmp = fill_tab(tab, piece, sqrsize);
				tmp = solver(tab, piece->next, sqrsize);
				if (tmp)
					return (tmp);
			}
			tab = retry(tab, piece->letter, sqrsize);
			x++;
		}
		y++;
	}
	return (NULL);
}

char	**fill_tab(char **tab, t_tetri *piece, int sqrsize) // Place le tetromino dans le tableau
{
	size_t i;
	size_t x;
	size_t y;

	i = 0;
	y = 0;
	while (y < sqrsize)
	{
		x = 0;
		while(x < sqrsize)
		{
			if(piece->x[i] == x && piece->y[i] == y)
			{
				tab[y][x] = piece->letter;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tab);
}

char	**fill_empty(char **tab, int sqrsize) // Remplis le tableau de points
{
	size_t y;
	size_t x;

	y = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (sqrsize + 1))))
		quit(ERROR);
	while (y < sqrsize)
	{
		tab[y] = ft_strnew(sqrsize);
		x = 0;
		while (x < sqrsize)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}
