/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:15:56 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 21:57:45 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check1(char **argv)
{
	int	i;
	int	j;
	int	r;

	i = 1;
	while (argv[i])
	{
		j = 0;
		r = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				r++;
			j++;
		}
		i++;
		if (r == 0)
			ft_exit(0);
	}
}

char	**get_arg(int argc, char **argv)
{
	char	*tmp;
	char	*array;
	int		i;
	char	**res;

	i = 0;
	array = ft_strdup("");
	while (i < argc)
	{
		tmp = array;
		array = ft_strjoin(array, argv[i]);
		free(tmp);
		tmp = array;
		array = ft_strjoin(array, " ");
		free(tmp);
		i++;
	}
	res = ft_split(array, ' ');
	free(array);
	return (res);
}

int	check(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_double(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	read_argv(char ***arg, t_Node **a)
{
	int		i;
	int		len;
	char	**argv;

	len = 0;
	argv = *arg;
	while (argv[len])
		len++;
	i = 1;
	if (check(argv, len) && check_double(argv, len))
	{
		i = len - 1;
		while (i > 0)
		{
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				ft_exit(0);
			push(a, ft_atoi(argv[i]));
			i--;
		}
	}
	else
		ft_exit(0);
	*arg = argv;
	return (len - 1);
}
