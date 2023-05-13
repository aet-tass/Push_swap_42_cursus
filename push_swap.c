/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/13 01:28:46 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_list  *lst_a;
    t_list  *lst_b;


    lst_a = NULL;
    lst_b = NULL;

    if (argc >= 2)
    {
		for (int i = 1; i < argc; i++)
        {
            ft_lstadd_back(&lst_a, ft_lstnew((void *)(intptr_t)ft_atoi(argv[i])));
        }

    //    if (check_duplicates(&lst_a->content, ft_lstsize(lst_a)) == 1)
    //     {
    //         ft_printf("Error");
    //         return (1);
    //     }

        //sa(&lst_a, 1);
        //sb(&lst_b, 1);
        //ss(&lst_a, &lst_b, 1);

        // Print out resulting lists
        ft_printf("List A: ");
        lst_print(lst_a);
        ft_printf("\n");

        //ft_printf("List B: ");
        //lst_print(lst_b);
        //ft_printf("\n");
    }
    else
        ft_printf("Error");

    // Free memory and exit program
    //ft_lstclear(&lst_a);
    //ft_lstclear(&lst_b);
    return 0;
}
