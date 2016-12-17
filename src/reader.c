/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:52 by aazri             #+#    #+#             */
/*   Updated: 2016/12/17 17:53:16 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

char	*read_file(int fd)
{
	size_t	i;
	char	tmp[BUFF_SIZE];
	char	buff;

	if (fd == -1)
		quit(ERROR);
	i = 0;
	while (read(fd, &buff, 1))
	{
		tmp[i] = buff;
		if (i > BUFF_SIZE)
			quit(ERROR);
		i++;
	}
	tmp[i] = '\0';
	close(fd);
	return (ft_strdup(tmp));
}

void	display_tab(char **tab)
{
	while (*tab)
		ft_putendl(*tab++);
}
