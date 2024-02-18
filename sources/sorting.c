/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:52 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 12:43:31 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//handle sorting a sequence of three elements using stack operations.
// It checks if the third element (str->a[2]) is not equal to 2.
// If true, it performs a rotation on stack a to move the largest
// or smallest element to the top, depending on whether str->a[0]
// is equal to 2 or not.After the rotation, it checks if the first
// element of stack a is greater than the second element. If true,
// it swaps the top two elements using swap("sa", ...)
void	sorting_3(t_stacks *str)
{
	if (str->a[2] != 2)
	{
		if (str->a[0] == 2)
			rotate(str->a, str->a_size, "up", "a");
		else
			rotate(str->a, str->a_size, "down", "a");
	}
	if (str->a[0] > str->a[1])
		swap("sa", str->a, str->a_size);
}

// This function handles sorting sequences of four or five elements.
// It uses stacks a and b. Here's what it does:
// It starts a loop that continues as long as str->b_size (size of stack b)
// is less than or equal to 1.
// Inside the loop, it checks the value of the first element of stack a:
// If the value is 0 or 1, it pushes the element to stack b.
// Otherwise, it performs a rotation on stack a.
// After the loop, it checks if the first element of stack b is 0 and
// swaps it with the second element using swap("sb", ...).
// It then checks if the third element of stack a is not equal to 4 
// and performs a rotation on stack a to bring the desired element to the top.
// Finally, it performs a check and swap operation similar to what was done in
// the sorting_3 function.
void	sorting_4_5(t_stacks *str)
{
	while (str->b_size <= 1)
	{
		if (str->a[0] == 0 || str->a[0] == 1)
			push("pb", str);
		else
			rotate(str->a, str->a_size, "up", "a");
	}
	if (str->b[0] == 0)
		swap("sb", str->b, str->b_size);
	if (str->a[2] != 4)
	{
		if (str->a[0] == 4)
			rotate(str->a, str->a_size, "up", "a");
		else
			rotate(str->a, str->a_size, "down", "a");
	}
	if (str->a[0] > str->a[1])
		swap("sa", str->a, str->a_size);
	push("pa", str);
	push("pa", str);
}

// This function checks whether the elements in stack a are already sorted
// in ascending order. It iterates through the elements and compares each 
// element with the next one. If any element is greater than its successor,
// the function returns 0 (not sorted); otherwise, it returns 1 (sorted).
int	already_sorted_or_not(t_stacks *str)
{
	int	index;

	index = 0;
	while (index < str->a_size - 1)
	{
		if (str->a[index] > str->a[index + 1])
			return (0);
		index++;
	}
	return (1);
}

// This function appears to be part of a radix sorting process involving
//stack b.It iterates through elements in stack b and performs rotations
//and pushes based on the bit value at the specified position (z) in the 
//binary representation of the elements. The main goal is to sort elements
//in stack a and stack b using radix sort.
static void	sorting_stckb_radix(t_stacks *str, int b_size, int bit_size, int z)
{
	while (b_size-- && z <= bit_size && !already_sorted_or_not(str))
	{
		if (((str->b[0] >> z) & 1) == 0)
			rotate(str->b, str->b_size, "up", "b");
		else
			push("pa", str);
	}
	if (already_sorted_or_not(str))
		while (str->b_size != 0)
			push("pa", str);
}

// This function implements a radix sorting algorithm. It iterates through
// different bit positions from least significant to most significant, 
// sorting elements in stack a and stack b based on the bit values at those
// positions.It uses the sorting_stckb_radix function to handle the sorting
// process for stack b.The process continues until the elements are fully
// sorted, with the most significant bit position being the last one.
void	radix_sorting(t_stacks *str)
{
	int	size;
	int	bit_size;	
	int	z;

	bit_size = 0;
	size = str->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	z = -1;
	while (++z <= bit_size)
	{
		size = str->a_size;
		while (size-- && !already_sorted_or_not(str))
		{
			if (((str->a[0] >> z) & 1) == 0)
				push("pb", str);
			else
				rotate(str->a, str->a_size, "up", "a");
		}
		sorting_stckb_radix(str, str->b_size, bit_size, z + 1);
	}
	while (str->b_size != 0)
		push("pa", str);
}
