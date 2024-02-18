/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:51 by zabdulza          #+#    #+#             */
/*   Updated: 2023/02/21 14:59:53 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int cons_byte, size_t n_bytesof_memory)
{
	char	*string;
	size_t	index;

	index = 0;
	string = (char *)pointer;
	while (index < n_bytesof_memory)
	{
		string[index] = cons_byte;
		index++;
	}
	return (pointer);
}
