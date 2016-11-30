/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:52 by aazri             #+#    #+#             */
/*   Updated: 2016/11/30 12:37:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *read_file(int fd) // Lit et stock le fichier dans une string
{
    size_t  i;
    char    tmp[545];
    char    buff;

    i = 0;
    while(read(fd, &buff, 1))
    {
		tmp[i] = buff;
		if (i > 545)
			quit(1);
		i++;
    }
    tmp[i] = '\0'; // Etrange bug d'affichage sur linux, a surveiller
    close(fd);
    return (ft_strdup(tmp));
}
