/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:31:13 by aazri             #+#    #+#             */
/*   Updated: 2016/12/04 22:20:27 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

#define false 0
#define true 1

typedef struct  s_tetri
{
    char    letter;
    char    *str;
    int     x[4];
    int     y[4];
    struct  s_tetri *next;
}               t_tetri;

char    *read_file(int fd);
size_t     tetri_counter(char *read);
t_tetri *stock_tetri(char *read);
t_tetri	*stock_pos(t_tetri *piece);
t_tetri	*tetri_initial_position(t_tetri *piece, char **tab);
void    quit(int error);
char	**fill_empty(char **tab, int sqrsize);
char	**solver(char **tab, t_tetri *piece, int sqrsize);
t_tetri *tetri_new_position(t_tetri *piece, size_t x, size_t y);
int	position_checker(char **tab, t_tetri *piece, int sqrsize);
char	**fill_tab(char **tab, t_tetri *piece, int sqrsize);

#endif
