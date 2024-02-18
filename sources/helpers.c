/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:07:00 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 12:43:14 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function checks if the input array is already sorted 
//or contains duplicate elements. 
// If it's sorted or has duplicates, the program exits with an error message.
void	if_duplic_sort_exit(t_stacks *str, int index)
{
	int	z;

	z = 0;
	if (index == 0)
	{
		while (index < str->a_size)
		{
			z = index + 1;
			while (z < str->a_size)
			{
				if (str->a[index] == str->a[z])
					exit_free_and_message(str, "Error: Duplicate found.\n");
				z++;
			}
			index++;
		}
	}
	if (already_sorted_or_not(str))
		exit_free_and_message(str, NULL);
}

// This function is responsible for parsing the input arguments,
// which are expected to be a space-separated list of numbers. 
// It uses the ft_split function to split the arguments 
//--into individual strings, 
// then converts each string to a number using the my_atol function, 
// and stores them in the a array of the t_stacks structure.
void	parse_nums(t_stacks *str)
{
	char	**temp;
	int		index;
	int		x;

	x = 0;
	temp = ft_split(str->argum_join, ' ');
	index = 0;
	while (temp[index] != NULL && temp[index][0] != '\0')
	{
		str->a[x++] = my_atol(temp[index++], str);
		free(temp[index - 1]);
	}
	free(temp);
}

// This function initializes the stacks and their sizes based
// on the input arguments. 
// It calculates the size of stack A based on the number of 
//space-separated elements in the input arguments. 
// It allocates memory for both stacks (a and b) and 
//handles potential allocation errors.
void	stack_building(int ac, char **av, t_stacks *str)
{
	int	index;

	index = 0;
	str->a_size = 0;
	str->b_size = 0;
	while (--ac)
	{
		if (ft_word_count(av[index + 1], ' '))
			str->a_size += ft_word_count(av[index + 1], ' ');
		else
			str->a_size++;
		index++;
	}
	str->a = malloc(str->a_size * sizeof * str->a);
	if (str->a == NULL)
		exit_free_and_message(str, "Error enter some sequence bro\n");
	str->b = malloc(str->a_size * sizeof * str->b);
	if (str->b == NULL)
		exit_free_and_message(str, "Error enter some sequence bro\n");
}

// This function creates an index array for the elements in stack A. 
// The index array represents the number of elements greater than 
//each element in stack A. 
// This index array will be used to optimize certain sorting operations.
void	index_array(t_stacks *str)
{
	int		index;
	int		z;
	int		m;
	int		*newa;

	newa = malloc(str->a_size * sizeof * newa);
	if (newa == NULL)
		exit_free_and_message(str, "Error!!!\n");
	index = -1;
	while (++index < str->a_size)
	{
		m = 0;
		z = -1;
		while (++z < str->a_size)
			if (str->a[index] > str->a[z])
				m++;
		newa[index] = m;
	}
	index = str->a_size;
	while (index--)
		str->a[index] = newa[index];
	free(newa);
}

// This function converts a string to an integer (with error handling) 
//using the atoi function 
// and performs additional checks for integer overflow. 
// It also uses the exit_free_and_message function to exit the 
//program with an error message 
// if conversion fails or if there's an overflow.
int	my_atol(const char *nptr, t_stacks *str)
{
	int			index;
	long		negative_sign;
	long long	result;

	result = 0;
	negative_sign = 1;
	index = 0;
	while (nptr[index] == ' ' || (nptr[index] >= '\t' && nptr[index] <= '\r'))
		index++;
	if ((nptr[index] == '+' || nptr[index] == '-'))
	{
		if (nptr[index] == '-')
			negative_sign = -1;
		index++;
	}
	while (nptr[index])
	{
		if (result > 2147483647 || (result * negative_sign) < -2147483648)
			exit_free_and_message(str, "Error!!!\n");
		if (!(nptr[index] >= '0' && nptr[index] <= '9'))
			exit_free_and_message(str, "Error!!!\n");
		result = result * 10 + (nptr[index++] - '0');
	}
	return ((int)(result * negative_sign));
}
