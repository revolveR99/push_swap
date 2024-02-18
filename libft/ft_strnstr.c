/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:35:31 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/09 12:17:45 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	n;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	h = 0;
	while (big[h])
	{
		n = 0;
		while (little[n] && big[h + n] == little[n] && h + n < len)
			n++;
		if (little[n] == '\0')
			return ((char *)&big[h]);
		h++;
	}
	return (NULL);
}
