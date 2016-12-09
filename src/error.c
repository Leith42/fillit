/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:17:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/09 13:12:49 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    quit(int error) // Simple gestion d'erreur
{
	if (error == ERROR)
		ft_putstr("error\n");
	else if (error == INVALID_ARGUMENT)
	{
		ft_putstr("fillit: invalid operand\n");
		ft_putstr("This program must take exactly one argument.\n");
	}
	exit(0);
}
