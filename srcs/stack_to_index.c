/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:46:30 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 21:52:30 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				c = tab[j];
				tab[j] = tab[i];
				tab[i] = c;
			}
			j ++;
		}
		i ++;
	}
}

void	to_index(t_Node **a, int *tab, int size)
{
	int		i;
	t_Node	*tmp;

	tmp = *a;
	while ((tmp) != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->data == tab[i])
			{
				tmp->data = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tmp);
}

void	stack_to_index(t_Node **a, int size)
{
	int		i;
	t_Node	*tmp;
	int		*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * size);
	tmp = *a;
	while (tmp != NULL)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_tab(&tab[0], size);
	to_index(a, &tab[0], size);
	free(tmp);
	free(tab);
}
