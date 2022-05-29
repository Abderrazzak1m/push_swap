/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:27:38 by amiski            #+#    #+#             */
/*   Updated: 2022/04/17 04:43:42 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	check_instructions(char *str, t_Node **a, t_Node **b)
{
	if (!ft_strncmp("sa\n", str, 3))
		run_ins(a, b, "sa", 0);
	else if (!ft_strncmp("sb\n", str, 3))
		run_ins(a, b, "sb", 0);
	else if (!ft_strncmp("ss\n", str, 3))
		run_ins(a, b, "ss", 0);
	else if (!ft_strncmp("pa\n", str, 3))
		run_ins(a, b, "pa", 0);
	else if (!ft_strncmp("pb\n", str, 3))
		run_ins(a, b, "pb", 0);
	else if (!ft_strncmp("ra\n", str, 3))
		run_ins(a, b, "ra", 0);
	else if (!ft_strncmp("rb\n", str, 3))
		run_ins(a, b, "rb", 0);
	else if (!ft_strncmp("rr\n", str, 3))
		run_ins(a, b, "rr", 0);
	else if (!ft_strncmp("rra\n", str, 4))
		run_ins(a, b, "rra", 0);
	else if (!ft_strncmp("rrb\n", str, 4))
		run_ins(a, b, "rrb", 0);
	else if (!ft_strncmp("rrr\n", str, 4))
		run_ins(a, b, "rrr", 0);
}

static void	get_instructions(t_Node **a, t_Node **b)
{
	char	*instructions;

	while (1)
	{
		instructions = get_next_line(0);
		if (!instructions)
			break ;
		check_instructions(instructions, a, b);
		free(instructions);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_Node	*b;
	t_Node	*a;

	i = 0;
	check1(argv);
	if (argc == 1)
		exit(0);
	argv = get_arg(argc, argv);
	argc = read_argv(&argv, &a);
	while (argv[i++])
		;
	stack_to_index(&a, i - 2);
	i = 1;
	if (argc > 0)
	{
		get_instructions(&a, &b);
		if (!is_sorted(a, b))
			i = -1;
		ft_exit(i);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
