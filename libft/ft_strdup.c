/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:37:07 by aazri             #+#    #+#             */
/*   Updated: 2016/12/09 17:44:12 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!(dest = malloc(sizeof(*src) * ft_strlen(src + 1))))
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}
