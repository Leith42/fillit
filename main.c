/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/29 16:26:55 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void algo(t_tetri *piece);

int main(int argc, char const *argv[])
{
    t_tetri *piece;
    char *read;

    if (argc != 2)
        quit(2);
    read = read_file(open(argv[1], O_RDONLY));
	piece = stock(read);
    piece = split(piece);
	/*while(piece->next)
	{
		ft_putstr(piece->str);
		piece = piece->next;
	}*/
	algo(piece);
    return (0);
}

void algo(t_tetri *piece)
{
	char tab[500][500] = {};
	int y = 0;
	int x = 0;
	int	b = 0;

	while (piece->next)
	{
		b = 0;
		while(b < 4)
		{
			tab[y][x] = piece->str[];
			b++;
			y++;
			x++;
		}
		y++;
		x++;
		piece = piece->next;
	}
	y = 0;
	while(tab[y])
	{
		b = 0;
		while(tab[y][b])
		{
			ft_putchar(tab[y][b]);
			b++;
		}
		y++;
	}
}
