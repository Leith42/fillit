/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/28 14:39:06 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		ft_putchar(piece->letter);
		piece = piece->next;
	}*/
    return (0);
}
