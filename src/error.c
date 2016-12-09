/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:17:01 by aazri             #+#    #+#             */
/*   Updated: 2016/12/09 17:05:34 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    quit(int error) // Simple gestion d'erreur
{
	if (error == ERROR)
		ft_putendl("error");
	else if (error == INVALID_ARGUMENT)
	{
		ft_putendl("fillit: invalid operand");
		ft_putendl("This program must take exactly one argument.");
	}
	exit(0);
}
