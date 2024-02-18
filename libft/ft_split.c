/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:18:23 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 11:57:45 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function counts the number of words in the input string str, 
// considering words separated by the delimiter character chr. 
// It iterates through the string character by character and 
// increments the countw variable whenever a non-delimiter character 
// is encountered after a delimiter or at the beginning of the string. 
// It then returns the count of words found in the string.
int	ft_word_count(char const *str, char chr)
{
	int	countw;

	countw = 0;
	while (*str)
	{
		if (*str != chr)
		{
			countw++;
			while (*str != chr && *str)
				str++;
		}
		else
			str++;
	}
	return (countw);
}

// This static function calculates the length of a word starting from
// the given index of the string str until either the delimiter character 
// chr or the end of the string is encountered. It iterates through the
//string 
// and increments the w_len variable to count the number of characters in 
//the word. 
// The function returns the length of the word.
static int	ft_word_len(char const *str, char chr, int index)
{
	int	w_len;

	w_len = 0;
	while (str[index] != chr && str[index++])
		w_len++;
	return (w_len);
}

//responsible for splitting the input string into an array of strings.
char	**ft_split(char const *str, char chr)
{
	int		w_count;
	int		index;
	int		zi;
	int		w_len;
	char	**parsed_w;	

	index = 0;
	zi = -1;
	w_count = ft_word_count(str, chr);
	parsed_w = (char **)malloc((w_count + 1) * sizeof(char *));
	if (!parsed_w)
		return (NULL);
	while (++zi < w_count)
	{
		while (str[index] == chr)
			index++;
		w_len = ft_word_len(str, chr, index);
		parsed_w[zi] = ft_substr(str, index, w_len);
		index = index + w_len;
	}
	parsed_w[zi] = 0;
	return (parsed_w);
}
