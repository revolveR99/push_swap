/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:52:53 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/10 09:52:56 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	unsigned int	i;

	i = 0;
	s_1 = (unsigned char *)string1;
	s_2 = (unsigned char *)string2;
	while (n--)
	{
		if (string1[i] != string2[i] ||!string1[i] ||!string2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}
