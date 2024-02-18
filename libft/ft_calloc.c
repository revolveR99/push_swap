/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:46:56 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/04 13:00:53 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t array, size_t size)
{
	void	*mem;
	size_t	msize;
	char	*p;

	msize = array * size;
	if (array == 0 || size == 0)
	{
		array = 1;
		msize = 1;
	}
	if ((msize) < array || (msize) < size)
		return (NULL);
	mem = malloc(msize);
	if (!mem)
		return (NULL);
	p = mem;
	while (msize--)
	{
		*p++ = 0;
	}
	return (mem);
}
