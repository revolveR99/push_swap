/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:35:24 by zabdulza          #+#    #+#             */
/*   Updated: 2023/02/28 13:46:07 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	z;

	z = ft_strlen(s);
	while (z >= 0)
	{
		if (s[z] == (char)c)
			return ((char *)s + z);
		z--;
	}
	return (NULL);
}
