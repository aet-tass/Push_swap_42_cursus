/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:17:43 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void perform_specific_sorting(t_list **lst_a, t_list **lst_b, int *sorted_arr)
{
    int lst_size = ft_lstsize(*lst_a);

    if (lst_size <= 3)
        sort_small(lst_a);
    else if (lst_size <= 5)
        sort_five(lst_a, lst_b);
    else if (lst_size <= 100)
        sort_range(lst_a, lst_b, 17, sorted_arr, lst_size);
    else if (lst_size <= 500)
        sort_range(lst_a, lst_b, 35, sorted_arr, lst_size);
}

void free_lists(t_list **lst_a, t_list **lst_b)
{
    ft_lstclear(lst_a);
    ft_lstclear(lst_b);
}

int perform_sorting(t_list *lst_a)
{
    t_list *lst_b = NULL;
    int *sorted_arr = create_sorted_array(lst_a);

    if (sorted_arr == NULL)
        return 1;

    perform_specific_sorting(&lst_a, &lst_b, sorted_arr);
    free_lists(&lst_a, &lst_b);

    return 0;
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

    return perform_sorting(lst_a);
}
