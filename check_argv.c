#include"push_swap.h"

static char	**get_arg(int argc, char **argv)
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

static int check(char **argv, int argc)
{
    int i;
    int j;
    i = 1;
    while(i < argc)
    {
        j = 0;
        if(argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while(argv[i][j])
        {
            if(argv[i][j] >= 48 || argv[i][j] <= 57)
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}
static int check_double(char **argv, int argc)
{
    int i;
    int j;

    i = 1;
    while(i < argc - 1)
    {
        j = i + 1;
        while(j < argc)
        {
            if( atoi(argv[i]) == atoi(argv[j]))
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}

void    read_argv(int argc, char **argv, Node **a)
{
    int i;
    int len;

    len = 0;
    argv = get_arg(argc, argv);
    while(argv[len])
        len++;
    i = 1;
    if(check(argv, len) && check_double(argv, len))
    {
        i = len - 1;
        while (i > 0)
        {
            push(a,ft_atoi(argv[i]));
            i--;
        }
     }
    else
        write(1, "Error", 5);
}