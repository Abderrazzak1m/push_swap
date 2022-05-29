/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:36:05 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 22:41:50 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include "../libfts/libfts.h"

typedef struct Node
{
	int			data;
	struct Node	*next;
}t_Node;

void	free_stack(t_Node **a);
void	initialize(t_Node **stack);
void	push(t_Node **stack, int num);
int		pop(t_Node **stack);
int		top(t_Node *stack);
t_Node	*new_node(int x);
void	swap(t_Node **a);
void	ss(t_Node **a, t_Node **b);
void	ft_push(t_Node **a, t_Node **b);
void	rotate(t_Node **a);
void	reverse_rotate(t_Node **a);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**get_arg(int argc, char **argv);
int		read_argv(char ***argv, t_Node **a);
//void    stack_to_index(Node **a, int size);
void	rrr(t_Node **a, t_Node **b);
void	rr(t_Node **a, t_Node **b);
void	run_ins(t_Node **a, t_Node **b, char *ins, int i);
int		push_med(t_Node **a, t_Node **b, int start, int end);
void	sort_a(t_Node **a, t_Node **b, int start, int end);
void	ft_sort(t_Node **a, t_Node **b, int len);
int		check(char **argv, int argc);
void	ft_exit(int s);
void	sort_tree(t_Node **a);
int		is_empty(t_Node **stack);
void	sort_five(t_Node **a, t_Node **b);
int		find_min(t_Node *a);
int		find_index(t_Node *a, int min);
int		check_nbr(t_Node *a);
void	sort_five(t_Node **a, t_Node **b);
void	stack_to_index(t_Node **a, int size);
void	sorta(t_Node **a, t_Node **b, int start, int end);
int		is_sorted(t_Node *a, t_Node *b);
char	*get_next_line(int fd);
void	free_array(char **tab);
void	push_medb(t_Node **a, t_Node **b, int start, int end);
void	check1(char **argv);
#endif
