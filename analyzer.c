/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:52:34 by aazri             #+#    #+#             */
/*   Updated: 2016/11/28 14:50:23 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri *stock(char *read) // Separe les tetrominos dans une liste
{
    size_t  i;
    size_t  b;
    char    letter;
    t_tetri *piece;
    t_tetri *tmp;

    i = tetri_counter(read);
    b = 0;
    letter = '1';
    piece = (t_tetri *)malloc(sizeof(t_tetri));
    tmp = piece;
    while(i > 0)
    {
		tmp->str = ft_strndup(&read[b], 20);
		tmp->letter = letter++;
		b += 21;
		tmp->next = (t_tetri *)malloc(sizeof(t_tetri));
		tmp = tmp->next;
		i--;
    }
	tmp->next = NULL;
	return (piece);
}

int tetri_counter(char *read) // Compte le nombre de tetrominos dans le fichier
{
	int diese;

	diese = 0;
	while (*read)
	{
		if (*read == '#')
			diese++;
		read++;
	}
	if (diese % 4 || diese < 4)
		quit(3);
	return (diese / 4);
}
