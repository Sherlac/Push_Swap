/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:32:56 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/18 17:09:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *a, t_stack *stacks)
{
	if (a[0] > a[1])
	{
		if (a[2] > a[0])
			sa(a, stacks);
		else if (a[2] > a[1])
			ra(a, stacks);
		else
		{
			sa(a, stacks);
			rra(a, stacks);
		}
	}
	else
	{
		if (a[2] > a[0])
		{
			ra(a, stacks);
			sa(a, stacks);
		}
		else
			rra(a, stacks);
	}
}

void	choose_algorithm(int *a, int *b, t_stack *stacks)
{
	if (stacks->a_size == 2)
		ra(a, stacks);
	if (stacks->a_size == 3)
		sort_three(a, stacks);
	else
		radix(a, stacks->a_size);
	b[0] = 0;
}

void	sort_stack(int *a, int *b, int stack_size)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return ;
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	choose_algorithm(a, b, stacks);
	free(stacks);
}

void	split_argv(char *str)
{
	char	**arr;
	int		stack_size;
	int		*a;
	int		*b;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		return ;
	stack_size = 0;
	while (arr[stack_size])
		stack_size++;
	a = malloc(sizeof(int) * stack_size);
	if (!a)
		return ;
	b = malloc(sizeof(int) * stack_size);
	if (!b)
		return ;
	if (ft_put_in_stack(a, b, arr, -1) == 1)
		if (is_sorted(a, stack_size) == -1)
			sort_stack(a, b, stack_size);
	free(a);
	free(b);
	free(arr);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		stack_size;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		split_argv(argv[1]);
	else
	{
		stack_size = (argc - 1);
		a = malloc(sizeof(int) * stack_size);
		if (!a)
			return (-1);
		b = malloc(sizeof(int) * stack_size);
		if (!b)
			return (-1);
		if (ft_put_in_stack(a, b, argv, 0) == 1)
			if (is_sorted(a, stack_size) == -1)
				sort_stack(a, b, stack_size);
		free(a);
		free(b);
	}
	return (0);
}
