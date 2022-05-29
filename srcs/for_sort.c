/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:24:36 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 22:24:49 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted(t_Node *a, t_Node *b)
{
	int	i;

	i = 0;
	if (b)
		return (0);
	while (a && ++i)
	{
		if (a->data != i)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sortb(t_Node **a, t_Node **b, int start, int end)
{
	int	med;
	int	r;
	int	len;

	r = 0;
	med = (start + end) / 2;
	len = end - start;
	if (start >= end || !(*b))
		return ;
	push_medb(a, b, start, end);
	sorta(a, b, med, end);
	sortb(a, b, start, med);
}

void	sorta(t_Node **a, t_Node **b, int start, int end)
{
	int				med;
	int				r;
	static t_Node	*s;

	med = (end + start) / 2;
	if (start > (end - 2))
	{
		if (*a && (*a)->next && (*a)->data > (*a)->next->data)
			run_ins(a, b, "sa", 1);
		return ;
	}
	r = push_med(a, b, start, end);
	if (s != NULL)
		while (r--)
			run_ins(a, b, "rra", 1);
	sorta(a, b, med + 1, end);
	s = *a;
	sortb(a, b, start, med);
}

void	ft_sort(t_Node **a, t_Node **b, int len)
{
	if (!is_sorted(*a, *b))
	{
		if (len <= 3)
			sort_tree(a);
		else if (len <= 5)
			sort_five(a, b);
		else
			sorta(a, b, 1, len);
	}
}

void	push_medb(t_Node **a, t_Node **b, int start, int end)
{
	int	r;
	int	med;
	int	len;

	r = 0;
	med = (start + end) / 2;
	len = end - start;
	while (*b && (*b)->data <= end && (*b)->data >= start)
	{
		if ((*b)->data >= med)
			run_ins(a, b, "pa", 1);
		else
		{
			run_ins(a, b, "rb", 1);
			r++;
		}
		if (!(len--))
			break ;
	}
	if (start != 1)
	{
		while (r-- > 0)
			run_ins(a, b, "rrb", 1);
	}
}
