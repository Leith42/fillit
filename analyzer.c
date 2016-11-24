/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:52:34 by aazri             #+#    #+#             */
/*   Updated: 2016/11/24 14:34:44 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_tetricounter(char *read) // Compte le nombre de tetrominos dans le fichier
{
	int diese;

	diese = 0;
	while (*read)
	{
		if (*read == '#')
			diese++;
		read++;
	}
	if (diese < 4)
		ft_error(1);
	return (diese / 4);
}
