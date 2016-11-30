/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:14:00 by aazri             #+#    #+#             */
/*   Updated: 2016/11/30 14:28:22 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**fill_empty(char **tab, int sqrsize) // Remplis le tableau de points
{
	int y;
	int x;

	y = 0;
	tab = (char **)malloc(sizeof(char *) * (sqrsize + 1));
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

int	sqroot(int n) // Racine carrée
{
	int size;

	size = 2;
	while(size * size < n)
		size++;
	return (size);
}
