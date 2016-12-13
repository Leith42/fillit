/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:52:34 by aazri             #+#    #+#             */
/*   Updated: 2016/12/13 15:11:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*glue_checker(int i, char *str)
{
	str[i] = '*';
	if (str[i + 1] == '#')
	{
		str[i + 1] = '*';
		str = glue_checker(i + 1, str);
	}
	if (str[i - 1] == '#')
	{
		str[i - 1] = '*';
		str = glue_checker(i - 1, str);
	}
	if (str[i + 5] == '#')
	{
		str[i + 5] = '*';
		str = glue_checker(i + 5, str);
	}
	if (str[i - 5] == '#')
	{
		str[i - 5] = '*';
		str = glue_checker(i - 5, str);
	}
	return (str);
}

int		position_checker(char **tab, t_tetri *piece, int sqrsize) // Vérifie si la position pour le tetromino entrant dans le tableau est prise
{
	int check;
	int x;
	int y;

	check = 0;
	y = 0;
	while (y < sqrsize)
	{
		x = 0;
		while (x < sqrsize)
		{
			if (piece->x[check] == x && piece->y[check] == y)
			{
				if (tab[y][x] != '.')
					return (FALSE);
				check++;
			}
			x++;
		}
		y++;
	}
	if (check != 4)
		return (FALSE);
	return (TRUE);
}

t_tetri	*stock_tetri(char *read) // Separe les tetrominos dans une liste
{
	size_t	i;
	size_t	pos;
	char	letter;
	t_tetri	*piece;
	t_tetri	*start;

	i = tetri_counter(read);
	pos = 0;
	letter = 'A';
	piece = (t_tetri *)malloc(sizeof(t_tetri));
	start = piece;
	while (i-- > 0)
	{
		piece->str = ft_strndup(&read[pos], 20);
		glue(piece->str);
		piece->letter = letter++;
		pos += 21;
		if (!(piece->next = (t_tetri *)malloc(sizeof(t_tetri))) || (read[pos - 1] != '\n' && i > 0))
			quit(ERROR);
		piece = piece->next;
	}
	piece->next = NULL;
	return (start);
}

int		tetri_counter(char *read)// Compte le nombre de tetrominos dans le fichier
{
	int hash;
	int	dot;
	int line;

	hash = 0;
	dot = 0;
	line = 0;
	while (*read)
	{
		if (*read == '#')
			hash++;
		else if (*read == '.')
			dot++;
		else if (*read == '\n')
			line++;
		else
			quit(ERROR);
		read++;
	}
	if (hash % 4 || hash < 4 || dot % 4 || (line + 1) % 5)
		quit(ERROR);
	return (hash / 4);
}

void	free_tetrominos(char **tab, t_tetri *piece)
{
	t_tetri *list;
	t_tetri *next;

	list = piece;
	free(tab);
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	piece = NULL;
}
