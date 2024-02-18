/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:35:46 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/04 13:05:08 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	outcome;
	int	i;
	int	signchange;

	signchange = 1;
	i = 0;
	outcome = 0;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\f'
		|| s[i] == '\n' || s[i] == ' ' || s[i] == '\r')
	{
		i++;
	}
	if (s[i] == '-')
	{
		signchange = signchange * -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		outcome = ((s[i] - '0') + (outcome * 10));
		i++;
	}
	return (outcome * signchange);
}
