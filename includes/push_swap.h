/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:50:50 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/19 12:04:30 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*argum_join;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sorting_3(t_stacks *str);
void		sorting_4_5(t_stacks *str);
void		radix_sorting(t_stacks *str);
void		parse_nums(t_stacks *str);
void		index_array(t_stacks *str);
void		stack_building(int ac, char **av, t_stacks *str);
void		exit_free_and_message(t_stacks *str, char *message);
void		if_duplic_sort_exit(t_stacks *str, int index);
int			already_sorted_or_not(t_stacks *str);
int			my_atol(const char *nptr, t_stacks *str);

#endif
