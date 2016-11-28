/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:31:13 by aazri             #+#    #+#             */
/*   Updated: 2016/11/28 14:39:21 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

typedef struct  s_tetri
{
    char    letter;
    char    *str;
    int     x[4];
    int     y[4];
    struct  s_tetri *next;
}               t_tetri;

char    *read_file(int fd);
int     tetri_counter(char *read);
t_tetri *stock(char *read);
t_tetri	*split(t_tetri *piece);
t_tetri	*tetri_position(t_tetri *piece, char **tab);
void    quit(int error);
#endif
