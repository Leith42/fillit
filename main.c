/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/30 14:26:16 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char const *argv[])
{
    t_tetri *piece;
    char *read;
	char **tab = NULL;

    if (argc != 2)
        quit(2);
    read = read_file(open(argv[1], O_RDONLY));
	piece = stock(read);
    piece = split(piece);
	tab = fill_empty(tab, sqroot(tetri_counter(read) * 4));
	while(*tab)
	{
		puts(*tab);
		tab++;
	}
    return (0);
}
