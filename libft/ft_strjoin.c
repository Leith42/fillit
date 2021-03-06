/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:29:00 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:33:33 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	if (s1 && s2)
	{
		ret = (char *)malloc(sizeof(*ret) * ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ret == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
		return (ret);
	}
	return (NULL);
}
