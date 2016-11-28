/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:17:01 by aazri             #+#    #+#             */
/*   Updated: 2016/11/28 14:37:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    quit(int er) // Simple gestion d'erreur
{
	if (er == 1)
		ft_putstr("error\n");
	else if (er == 2)
	{
		ft_putstr("fillit: invalid operand\n");
		ft_putstr("This program must take exactly one argument.\n");
	}
	else if (er == 3)
		ft_putstr("bad boy");
	exit(0);
}
