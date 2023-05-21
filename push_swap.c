/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 00:39:39 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int *sort_arr(int *arr, int n)
{
    int i = 0;
    int j = 0;
    int sorted = 0;

    while (i < n - 1)
    {
        j = 0;
        while (j < n - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sorted = 1;
            }
            j++;
        }

        if (sorted == 0)
            break;

        i++;
    }

    return arr;
}


int     main(int argc, char **argv)
{
    t_list  *lst_a;
    t_list  *lst_b;
    int     *sorted_arr;
    char    *str;
    char    **spt;
    int     i;


    lst_a = NULL;
    lst_b = NULL;
    i = 1;
    str = ft_strdup("");
    if (argc >= 2)
    {
        while (i < argc)
        {
            str = ft_strjoin(str, argv[i]);
            str = ft_strjoin(str, " ");
            i++;
        }
        spt = ft_split(str, ' ');
        i = 0;
        while (spt[i])
        {
            int num = ft_atoi(spt[i]);
            void *num_ptr = (void *)malloc(sizeof(int));
            *(int *)num_ptr = num;
            ft_lstadd_back(&lst_a, ft_lstnew(num_ptr));
            i++;
        }
        if (check_duplicates(lst_a) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            return (1);
        }
        else if (is_sorted(lst_a) == 1)
            return (1);
        sorted_arr = (int *)malloc(sizeof(int) * ft_lstsize(lst_a));
        for (int i = 0; i < ft_lstsize(lst_a); i++)
            sorted_arr[i] = ft_atoi(argv[i + 1]);
        sorted_arr = sort_arr(sorted_arr, ft_lstsize(lst_a));
        if (ft_lstsize(lst_a) <= 3)
            sort_small(&lst_a);
        else if (ft_lstsize(lst_a) <= 5)
        {
                sort_five(&lst_a, &lst_b);
        }
        else if (ft_lstsize(lst_a) <= 100)
                sort_range(&lst_a, &lst_b, 17, sorted_arr, ft_lstsize(lst_a));
        else if (ft_lstsize(lst_a) <= 500)
                sort_range(&lst_a, &lst_b, 35, sorted_arr, ft_lstsize(lst_a));
    }
    else
        return (1);
    // lst_my_print(lst_a);

    ft_lstclear(&lst_a);
    ft_lstclear(&lst_b);
    return (0);
}
