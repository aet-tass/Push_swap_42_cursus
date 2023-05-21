/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/21 01:54:00 by aet-tass         ###   ########.fr       */
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
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    return (arr);
}

int     main(int argc, char **argv)
{
    t_list  *lst_a;
    t_list  *lst_b;
    int     *sorted_arr;
    int     i;


    lst_a = NULL;
    lst_b = NULL;
    i = 1;
    (void)lst_b;
    if (argc >= 2)
    {
        while (i < argc)
        {
            int num = ft_atoi(argv[i]);
            void *num_ptr = (void *)malloc(sizeof(int));
            *(int *)num_ptr = num;
            ft_lstadd_back(&lst_a, ft_lstnew(num_ptr));
            i++;
        }
        if (check_duplicates(lst_a) == 1)
        {
            printf("Error\n");
            return (1);
        }
        else if (is_sorted(lst_a) == 1)
            return (1);
        sorted_arr = (int *)malloc(sizeof(int) * ft_lstsize(lst_a));
        for (int i = 0; i < ft_lstsize(lst_a); i++)
            sorted_arr[i] = atoi(argv[i + 1]);
        sorted_arr = sort_arr(sorted_arr, ft_lstsize(lst_a));
        if (ft_lstsize(lst_a) <= 3)
            sort_small(&lst_a);
        else if (ft_lstsize(lst_a) <= 5)
                sort_five(&lst_a, &lst_b);
        else if (ft_lstsize(lst_a) <= 100)
                sort_range(&lst_a, &lst_b, 19, sorted_arr, ft_lstsize(lst_a));
        // else if (ft_lstsize(lst_a) <= 500)
        //         sort_range(&lst_a, &lst_b, 35, sorted_arr, ft_lstsize(lst_a));



        //sa(&lst_a, 1);
        //sb(&lst_b, 1);
        //ss(&lst_a, &lst_b, 1);

        // Print out resulting lists
    //     printf("List A: ");
    //    lst_print(lst_a);
    //    printf("\n");
        // printf("List B: ");
        // lst_print(lst_b);
        // printf("\n");
    }
    else
        return (1);

    // Free memory and exit program
    //ft_lstclear(&lst_a);
    //ft_lstclear(&lst_b);
    return (0);
}
