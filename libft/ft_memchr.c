/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:42:39 by zabdulza          #+#    #+#             */
/*   Updated: 2023/02/21 17:49:29 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch2;

	s = (unsigned char *)str;
	ch2 = (unsigned char)c;
	while (n--)
	{
		if (*s == ch2)
			return ((void *)s);
		s++;
	}
	return (0);
}
