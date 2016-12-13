/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:14:00 by aazri             #+#    #+#             */
/*   Updated: 2016/12/13 15:40:55 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**retry(char **tab, char letter, int sqrsize)
{
	int x;
	int y;

	y = 0;
	while (y < sqrsize)
	{
		x = 0;
		while (x < sqrsize)
		{
			if (tab[y][x] == letter)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char	**solver(char **tab, t_tetri *piece, int sqr)
{
	int		x;
	int		y;
	char	**tmp;

	if (!piece->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < sqr)
	{
		x = 0;
		while (x < sqr)
		{
			piece = tetri_new_position(piece, x, y);
			if (position_checker(tab, piece, sqr))
				tmp = solver(fill_tab(tab, piece, sqr), piece->next, sqr);
			if (tmp)
				return (tmp);
			tab = retry(tab, piece->letter, sqr);
			x++;
		}
		y++;
	}
	return (NULL);
}

char	**fill_tab(char **tab, t_tetri *piece, int sqrsize)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < sqrsize)
	{
		x = 0;
		while (x < sqrsize)
		{
			if (piece->x[i] == x && piece->y[i] == y)
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

char	**fill_empty(char **tab, int sqrsize)
{
	int y;
	int x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (sqrsize + 1))))
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
