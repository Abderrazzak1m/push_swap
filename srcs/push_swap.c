/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:40:32 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 22:50:43 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	while (argv[++i])
		;
	stack_to_index(&a, i - 1);
	if (argc > 1)
	{
		ft_sort(&a, &b, i - 1);
	}
	free_stack(&a);
	free_stack(&b);
	free_array(argv);
	free(argv);
	return (0);
}
