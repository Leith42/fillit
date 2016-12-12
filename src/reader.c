/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:52 by aazri             #+#    #+#             */
/*   Updated: 2016/12/12 17:14:49 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	star_counter(char *str)
{
	int star;

	star = 0;
	while (*str)
	{
		if (*str == '*')
			star++;
		str++;
	}
	if (star != 4)
		quit(ERROR);
}

char	*read_file(int fd) // Lit et stock le fichier dans une string
{
	size_t	i;
	char	str[MAX_TETROMINOS];
	char	buff;

	if (fd == -1)
		quit(ERROR);
	i = 0;
	while (read(fd, &buff, 1))
	{
		str[i] = buff;
		if (i > MAX_TETROMINOS)
			quit(ERROR);
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (ft_strdup(str));
}

void	display_fillit(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}
