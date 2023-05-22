/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:17:07 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:32:23 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *join_arguments(int argc, char **argv)
{
    char *str = ft_strdup("");

    if (argc >= 2)
    {
        int i = 1;
        while (i < argc)
        {
            str = ft_strjoin(str, argv[i]);
            str = ft_strjoin(str, " ");
            i++;
        }
    }

    return str;
}

char **split_arguments(char *str)
{
    return ft_split(str, ' ');
}

t_list *create_list(char **spt)
{
    t_list *lst_a = NULL;
    int i = 0;

    while (spt[i])
    {
        int num = ft_atoi(spt[i]);
        void *num_ptr = (void *)malloc(sizeof(int));
        *(int *)num_ptr = num;

        ft_lstadd_back(&lst_a, ft_lstnew(num_ptr));
        i++;
    }

    return lst_a;
}

t_list *parse_arguments(int argc, char **argv)
{
    char *str = join_arguments(argc, argv);
    char **spt = split_arguments(str);
    t_list *lst_a = create_list(spt);

    return lst_a;
}
int	find_index(int *arr, int size, int num)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == num)
			return (index);
		index++;
	}
	return (-1);
}
