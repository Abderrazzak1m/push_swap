/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:12:16 by amiski            #+#    #+#             */
/*   Updated: 2022/01/16 02:21:39 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(Node **a)
{
	int	i;
	int	j;

	i = pop(a);
	j = pop(a);
	push(a, i);
	push(a, j);
}

void	ss(Node **a, Node **b)
{
	swap(a);
	swap(b);
}

void	p(Node **a, Node **b)
{
	push(a, pop(b));
}

void	r(Node **a)
{
	Node	*p;
	Node	*current;

	p = newNode(pop(a));
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

void	rr(Node **a)
{
	int		num;
	Node	*current;
	Node	*prev;

	if (*a != NULL)
	{
		current = *a;
		prev = current;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		num = current->data;
		prev->next = NULL;
		push(a, num);
	}
}
