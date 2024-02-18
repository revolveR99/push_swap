/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:41 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 12:43:27 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// The purpose of this function seems to be to swap the first two elements of
// the array and print the given string using ft_putendl_fd.
// It does the following:
// Checks if size is less than or equal to 0 and returns if true.
// Swaps the first and second elements of the array.
// Prints the given str using ft_putendl_fd.
void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

// The purpose of this function seems to be to implement the push operation
// between two stacks ('a' and 'b'). The function does the following:
// Checks if str matches "pa" or "pb":
// If it's "pa", it moves an element from stack 'b' to stack 'a'.
// If it's "pb", it moves an element from stack 'a' to stack 'b'.
// Moves elements in the arrays and updates the sizes of the stacks.
// Prints the given str using ft_putendl_fd.
void	push(char *str, t_stacks *s)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->b_size <= 0)
			return ;
		tmp = s->b[0];
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
		s->a[0] = tmp;
		s->b_size--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
		s->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->a_size <= 0)
			return ;
		tmp = s->a[0];
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
		s->b[0] = tmp;
		s->a_size--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
		s->b_size++;
	}
	ft_putendl_fd(str, 1);
}

// The purpose of this function seems to be to perform rotation operations on
// an array based on the specified direction. It does the following:
// Checks if size is less than 0 and returns if true.
// Checks the value of direction:
// If it's "up", it rotates the array elements to the right (circular shift).
// If it's "down", it rotates the array elements to the left 
// (circular shift in the opposite direction).
// Prints either "r" or "rr" based on the direction using the write function.
// Prints the given list using ft_putendl_fd.
void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
