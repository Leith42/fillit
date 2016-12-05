/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:17:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/05 19:03:41 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    quit(int error) // Simple gestion d'erreur
{
	if (ERROR)
		ft_putstr("error\n");
	else if (INVALID)
	{
		ft_putstr("fillit: invalid operand\n");
		ft_putstr("This program must take exactly one argument.\n");
	}
	exit(FALSE);
}
