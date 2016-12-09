/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:52 by aazri             #+#    #+#             */
/*   Updated: 2016/12/09 14:10:58 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(int fd)// Lit et stock le fichier dans une string
{
	size_t	i;
	char	tmp[MAX_TETROMINOS];
	char	buff;

	if (fd == -1)
		quit(ERROR);
	i = 0;
	while (read(fd, &buff, 1))
	{
		tmp[i] = buff;
		if (i > MAX_TETROMINOS)
			quit(ERROR);
		i++;
	}
	tmp[i] = '\0';
	close(fd);
	glue(tmp);
	return (ft_strdup(tmp));
}

void	display_tab(char **tab)
{
	while (*tab)
		ft_putendl(*tab++);
}
