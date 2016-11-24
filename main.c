/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:50:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/24 14:08:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char const *argv[])
{
    t_tetri *piece;
    char *read;

    if (argc != 2)
        ft_error(2);
    read = ft_readfile(open(argv[1], O_RDONLY));
    piece = ft_stock(read);
	/*while(piece->next)
	{
		puts(piece->str);
		piece = piece->next;
	}*/
    return (0);
}
