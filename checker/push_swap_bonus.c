/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:50:49 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:57:25 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"
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
int *create_sorted_array(t_list *lst_a)
{
    int *sorted_arr = (int *)malloc(sizeof(int) * ft_lstsize(lst_a));
    if (sorted_arr == NULL)
    {
        ft_putstr_fd("Memory allocation failed\n", 2);
        return NULL;
    }

    int i = 0;
    t_list *current = lst_a;

    while (current != NULL)
    {
        sorted_arr[i] = *(int *)(current->content);
        current = current->next;
        i++;
    }

    return sorted_arr;
}

int main(int argc, char **argv)
{
    t_list *lst_a;

    lst_a = parse_arguments(argc, argv);

    if (lst_a == NULL)
        return 1;

    if (check_duplicates(lst_a) == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return 1;
    }

    if (is_sorted(lst_a) == 1)
        return 1;

}

