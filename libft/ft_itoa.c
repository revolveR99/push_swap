/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:39:03 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/04 13:10:47 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_sizeofword(int z)
{
	unsigned int	size;

	size = 0;
	if (z <= 0)
		size ++;
	while (z != 0)
	{
		z /= 10;
		size += 1;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	length;
	char			*string;
	unsigned int	number;

	length = ft_sizeofword(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (0);
	if (n < 0)
	{
		string[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		string[0] = '0';
	string[length] = '\0';
	while (number > 0)
	{
		string[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (string);
}
