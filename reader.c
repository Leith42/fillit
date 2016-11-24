/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:52 by aazri             #+#    #+#             */
/*   Updated: 2016/11/24 14:34:33 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri *ft_stock(char *read) // Separe les tetrominos dans une liste
{
    size_t  i;
    size_t  b;
    char    letter;
    t_tetri *piece;
    t_tetri *tmp;

    i = ft_tetricounter(read);
    b = 0;
    letter = '1';
    piece = (t_tetri *)malloc(sizeof(t_tetri));
    tmp = piece;
    while(i > 0)
    {
		tmp->str = ft_strndup(&read[b], 20);
		tmp->letter = ++letter;
		b += 21;
		tmp->next = (t_tetri *)malloc(sizeof(t_tetri));
		tmp = tmp->next;
		i--;
    }
	tmp->next = NULL;
	return (piece);
}

char    *ft_readfile(int fd) // Lit et stock le fichier dans une string
{
    size_t  i;
    char    tmp[545];
    char    buff;

    i = 0;
    while(read(fd, &buff, 1))
    {
		tmp[i] = buff;
		if (i > 545)
			ft_error(2);
		i++;
    }
    tmp[--i] = '\0'; // Temporaire, fix un bug avec deux tetris
    close(fd);
    return (ft_strdup(tmp));
}
