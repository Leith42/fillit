/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <mmatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:26:08 by mmatime           #+#    #+#             */
/*   Updated: 2016/12/17 17:52:26 by aazri            ###   ########.fr       */
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
	return (str);
}

int		position_checker(char **tab, t_tetri *piece, int sqrsize)
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

t_tetri	*stock_tetri(char *read)
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
		if (!(piece->next = (t_tetri *)malloc(sizeof(t_tetri)))
		|| (read[pos - 1] != '\n' && i > 0))
			quit(ERROR);
		piece = piece->next;
	}
	piece->next = NULL;
	return (start);
}

int		tetri_counter(char *read)
{
	int hash;
	int	dot;
	int line;

	hash = 0;
	dot = 0;
	line = 1;
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
	if (hash % 4 || hash < 4 || dot % 4 || line % 5)
		quit(ERROR);
	return (hash / 4);
}

void	free_tetrominos(char **tab, t_tetri *piece, char *read)
{
	t_tetri *list;
	t_tetri *next;

	list = piece;
	free(tab);
	free(read);
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	piece = NULL;
}
