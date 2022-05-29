/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:04:18 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 18:12:46 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	reverse_rotate(t_Node **a)
{
	int		num;
	t_Node	*current;
	t_Node	*prev;

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
		free(current);
	}
}

void	rrr(t_Node **a, t_Node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
