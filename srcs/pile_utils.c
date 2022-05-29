/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:32:34 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 17:55:27 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_Node	*new_node(int x)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return (newnode);
}

void	push(t_Node **stack, int num)
{
	t_Node	*p;

	p = new_node(num);
	p->next = *stack;
	*stack = p;
}

int	pop(t_Node **stack)
{
	t_Node	*forfree;
	int		top;

	if (*stack == NULL)
	{
		return (-1);
	}
	else
	{
		forfree = *stack;
		top = (*stack)->data;
		*stack = (*stack)->next;
		free(forfree);
		return (top);
	}
}

int	top(t_Node *stack)
{
	if (stack == NULL)
	{
		return (-1);
	}
	else
		return (stack->data);
}

int	is_empty(t_Node **stack)
{
	if (*stack == NULL)
		return (1);
	return (0);
}
