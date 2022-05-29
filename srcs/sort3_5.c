/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:34:49 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 22:39:38 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_tree(t_Node **a)
{
	t_Node	*tmp;
	int		b;
	int		c;

	tmp = *a;
	b = tmp->data;
	c = tmp->next->data;
	if (*a && (*a)->next && (*a)->next->next)
	{
		if (tmp->data > tmp->next->data && tmp->data > tmp->next->next->data)
			run_ins(&tmp, NULL, "ra", 1);
		if (tmp->data < tmp->next->data \
		&& tmp->next->data > tmp->next->next->data)
			run_ins(&tmp, NULL, "rra", 1);
		if (tmp->data > tmp->next->data)
			run_ins(&tmp, NULL, "sa", 1);
		*a = tmp;
	}
	else if (*a && (*a)->next && (*a)->data > (*a)->next->data)
		run_ins(a, NULL, "sa", 1);
}

void	sort_five(t_Node **a, t_Node **b)
{
	int	i;

	i = 0;
	while (++i <= 2)
	{
		while ((*a)->data >= 3)
			run_ins(a, b, "ra", 1);
		run_ins(a, b, "pb", 1);
	}
	sort_tree(a);
	if ((*b)->data < (*b)->next->data)
		run_ins(a, b, "sb", 1);
	run_ins(a, b, "pa", 1);
	run_ins(a, b, "pa", 1);
}

void	free_stack(t_Node **a)
{
	t_Node	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	free_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
}
