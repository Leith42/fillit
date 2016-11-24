/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:31:13 by aazri             #+#    #+#             */
/*   Updated: 2016/11/24 12:33:20 by aazri            ###   ########.fr       */
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

char    *ft_readfile(int fd);
int     ft_tetricounter(char *read);
t_tetri *ft_stock(char *read);
void    ft_error(int error);
#endif
