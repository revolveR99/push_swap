/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:04:59 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/04 12:17:09 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_one;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new_one = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new_one == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_one[i] = f(i, s[i]);
		i++;
	}
	new_one[i] = '\0';
	return (new_one);
}
