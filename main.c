/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/29 16:57:05 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void algo(t_tetri *piece);

int main(int argc, char const *argv[])
{
    t_tetri *piece;
    /*char *read;

    if (argc != 2)
        quit(2);
    read = read_file(open(argv[1], O_RDONLY));
	piece = stock(read);
    piece = split(piece);
	while(piece->next)
	{
		ft_putstr(piece->str);
		piece = piece->next;
	}*/
	algo(piece);
    return (0);
}

void algo(t_tetri *piece)
{
	char tab[300][300];
	int y = 0;
	int x = 0;
	int	i = 0;
	int j = 0;

	while (y < 300)
	{
		x = 0;
		while (x < 300)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	printf("%c\n", tab[14][15]);
	printf("%c\n", tab[100][150]);
	printf("%c\n", tab[10][2]);
}
