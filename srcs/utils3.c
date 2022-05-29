/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:13:58 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 18:22:00 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	run_ins(t_Node **a, t_Node **b, char *ins, int i)
{
	if (!ft_strncmp(ins, "sa", 4) || !ft_strncmp(ins, "ss", 4))
		swap(a);
	if (!ft_strncmp(ins, "sb", 4) || !ft_strncmp(ins, "ss", 4))
		swap(b);
	if (!ft_strncmp(ins, "pa", 4))
		ft_push(a, b);
	if (!ft_strncmp(ins, "pb", 4))
		ft_push(b, a);
	if (!ft_strncmp(ins, "ra", 4) || !ft_strncmp(ins, "rr", 4))
		rotate(a);
	if (!ft_strncmp(ins, "rb", 4) || !ft_strncmp(ins, "rr", 4))
		rotate(b);
	if (!ft_strncmp(ins, "rra", 4) || !ft_strncmp(ins, "rrr", 4))
		reverse_rotate(a);
	if (!ft_strncmp(ins, "rrb", 4) || !ft_strncmp(ins, "rrr", 4))
		reverse_rotate(b);
	if (i)
	{
		ft_putstr_fd(ins, 1);
		write(1, "\n", 1);
	}
}

int	push_med(t_Node **a, t_Node **b, int start, int end)
{
	int	med;
	int	r;
	int	len;

	med = (end + start) / 2;
	len = end - start;
	r = 0;
	while (*a && (*a)->data <= end && (*a)->data >= start)
	{
		if ((*a)->data <= med)
		{
			run_ins(a, b, "pb", 1);
		}
		else
		{
			run_ins(a, b, "ra", 1);
			r++;
		}
		if (!len--)
			break ;
	}
	return (r);
}

void	ft_exit(int s)
{
	if (s == 0)
		write(1, "Error\n", 6);
	else if (s == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

void	initialize(t_Node **stack)
{
	*stack = NULL;
}
