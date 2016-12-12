/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:31:13 by aazri             #+#    #+#             */
/*   Updated: 2016/12/12 17:14:39 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

# define FALSE 0
# define TRUE 1
# define MAX_TETROMINOS 26 * 21 - 1

enum	{INVALID_ARGUMENT, ERROR};

typedef struct	s_tetri
{
	char			letter;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}				t_tetri;

char			*read_file(int fd);
char			**fill_empty(char **tab, int sqrsize);
char			**fill_tab(char **tab, t_tetri *piece, int sqrsize);
char			**solver(char **tab, t_tetri *piece, int sqrsize);
t_tetri			*stock_tetri(char *read, size_t i);
t_tetri			*stock_pos(t_tetri *piece);
t_tetri			*tetri_initial_position(t_tetri *piece, char **tab);
t_tetri			*tetri_new_position(t_tetri *piece, size_t x, size_t y);
int				tetri_counter(char *read);
int				position_checker(char **tab, t_tetri *piece, int sqrsize);
void			display_fillit(char **tab);
void			fill_free(char **tab, t_tetri *piece, char *read);
void			star_counter(char *str);
void			glue(char *str);
char			*glue_checker(int i, char *str);
void			quit(int error);

#endif
