/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:12:16 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 18:06:28 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_Node **a)
{
	int	i;
	int	j;

	i = pop(a);
	j = pop(a);
	push(a, i);
	push(a, j);
}

void	ss(t_Node **a, t_Node **b)
{
	swap(a);
	swap(b);
}

void	ft_push(t_Node **a, t_Node **b)
{
	push(a, pop(b));
}

void	rotate(t_Node **a)
{
	t_Node	*p;
	t_Node	*current;

	p = new_node(pop(a));
	if (*a == NULL)
	{
		*a = p;
	}
	else
	{
		current = *a;
		while (current->next != NULL)
			current = current->next;
		current->next = p;
	}
}

void	rr(t_Node **a, t_Node **b)
{
	rotate(a);
	rotate(b);
}
