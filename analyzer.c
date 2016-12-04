/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:52:34 by aazri             #+#    #+#             */
/*   Updated: 2016/12/04 22:25:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	position_checker(char **tab, t_tetri *piece, int sqrsize) // Vérifie si la position pour le tetromino entrant dans le tableau est prise
{
	size_t check;
	size_t x;
	size_t y;

	check = 0;
	y = 0;
	while(y < sqrsize)
	{
		x = 0;
		while(x < sqrsize)
		{
			if (piece->x[check] == x && piece->y[check] == y)
			{
				if(tab[y][x] != '.')
					return (false);
				check++;
			}
			x++;
		}
		y++;
	}
	if(check != 4)
		return (false);
	return (true);
}

t_tetri *stock_tetri(char *read) // Separe les tetrominos dans une liste
{
    size_t  i;
    size_t  pos;
    char    letter;
    t_tetri *piece;
    t_tetri *tmp;

    i = tetri_counter(read);
    pos = 0;
    letter = 'A';
    piece = (t_tetri *)malloc(sizeof(t_tetri));
    tmp = piece;
    while(i > 0)
    {
		tmp->str = ft_strndup(&read[pos], 20);
		tmp->letter = letter++;
		pos += 21;
		tmp->next = (t_tetri *)malloc(sizeof(t_tetri));
		tmp = tmp->next;
		i--;
    }
	tmp->next = NULL;
	return (piece);
}

size_t tetri_counter(char *read) // Compte le nombre de tetrominos dans le fichier
{
	size_t diese;

	diese = 0;
	while (*read)
	{
		if (*read == '#')
			diese++;
		read++;
	}
	if (diese % 4 || diese < 4)
		quit(1);
	return (diese / 4);
}
