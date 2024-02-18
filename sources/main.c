/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:34 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 12:43:22 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function is responsible for handling errors, freeing memory,
// and displaying error messages. It is used to terminate the program
// with an error message if something goes wrong during execution.
// It takes a pointer to a t_stacks structure and an error message
// string as parameters.
void	exit_free_and_message(t_stacks *str, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (str != NULL)
	{
		if (str->a != NULL)
			free(str->a);
		if (str->b != NULL)
			free(str->b);
		if (str->argum_join != NULL)
			free(str->argum_join);
		if (str != NULL)
			free(str);
	}
	exit(1);
}

// This function is used to validate the command-line arguments passed 
// to the program. It checks whether the arguments are valid integers or not.
// It also handles cases  where there are not enough arguments or where
// an empty argument is encountered.If the validation fails,
// the exit_free_and_message function is called to display
// an error message and free any allocated memory.
static void	argument_validation(int ac, char **av)
{
	int	inx;
	int	z;

	inx = 0;
	if (ac < 2)
		exit_free_and_message(NULL, "");
	while (++inx < ac)
	{
		z = 0;
		if (av[inx][0] == '\0')
			exit_free_and_message(NULL, "Error\n");
		while (av[inx][z] != '\0')
		{
			if ((!(ft_isdigit(av[inx][z])) && (av[inx][z] != ' ')
			&& (av[inx][z] != '-' && av[inx][z] != '+' && av[inx][z] != ' '))
			|| (av[inx][z] == '-' && av[inx][z + 1] == '\0')
			|| (av[inx][z] == '+' && av[inx][z + 1] == '\0')
			|| (av[inx][z] == '-' && av[inx][z + 1] == ' ')
			|| (av[inx][z] == '+' && av[inx][z + 1] == ' '))
				exit_free_and_message(NULL, "Error\n");
			z++;
		}
	}
}

// This function is responsible for joining the command-line arguments
// into a single string, separated by spaces. It creates a string 
// containing all the arguments separated by spaces and assigns it 
// to the argum_join field in the t_stacks structure. This concatenated
// string is later used for error messages and debugging purposes.
static void	argum_join(int ac, char **av, t_stacks *str)
{
	int		index;
	char	*temporary;
	char	*temporary2;

	index = 0;
	temporary2 = ft_strdup("");
	while (++index < ac && av[index] != NULL)
	{
		temporary = ft_strjoin(temporary2, av[index]);
		if (temporary2)
			free(temporary2);
		if (index != ac - 1)
		{
			temporary2 = ft_strjoin(temporary, " ");
			if (temporary)
				free(temporary);
			temporary = temporary2;
		}
	}
	str->argum_join = ft_strdup(temporary);
	if (str->argum_join == NULL)
		exit_free_and_message(str, "Error\n");
	if (temporary)
		free(temporary);
}

// argument_validation(ac, av): This function is called to validate the
// command-line arguments.Memory is allocated for a t_stacks structure
// using malloc.
// stack_building(ac, av, str): This function presumably initializes
// the t_stacks structure with the given command-line arguments.
// argum_join(ac, av, str): This function is called to concatenate
// the command-line arguments into a single string.
// parse_nums(str): This function might parse the concatenated
// string of arguments and populate the integer arrays in the 
//t_stacks structure.
// if_duplic_sort_exit(str, 0): This function checks for duplicate
// numbers and sorts the str->a array if there are no duplicates.
// If duplicates are found, it exits with an error message.
// index_array(str): This function could assign indices to the 
// elements of the str->a array.
// Sorting operations are performed based on the size of the array.
// The program seems to use different sorting algorithms for arrays
// of different sizes.
// if_duplic_sort_exit(str, 1): This function is called again to handle
// duplicates and sorting after the main sorting operations.
// Finally, the exit_free_and_message function is called to exit the program,
// freeing memory and displaying an error message.
int	main(int ac, char **av)
{
	t_stacks	*str;

	argument_validation(ac, av);
	str = malloc(sizeof * str);
	if (str == NULL)
		exit(1);
	stack_building(ac, av, str);
	argum_join(ac, av, str);
	parse_nums(str);
	if_duplic_sort_exit(str, 0);
	index_array(str);
	if (str->a_size == 2 && str->a[0] > str->a[1])
		swap("sa", str->a, str->a_size);
	else if (str->a_size == 3)
		sorting_3(str);
	else if (str->a_size >= 4 && str->a_size <= 5)
		sorting_4_5(str);
	else
		radix_sorting(str);
	if_duplic_sort_exit(str, 1);
	exit_free_and_message(str, "Error\n");
	return (0);
}
