/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/10 22:45:28 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_list  *lst_a;    // Pointer to the head node of list A
    t_list  *lst_b;    // Pointer to the head node of list B
   // int     i;

    lst_a = NULL;
    lst_b = NULL;

    // Check the provided arguments
    if (argc && argv)
    {
        // Populate list A with provided arguments
		for (int i = 1; i < argc; i++)
            ft_lstadd_back(&lst_a, ft_lstnew(ft_atoi(argv[i])));
		// Example usage of sorting functions
        sa(&lst_a, 1);
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

    // Free memory and exit program
    //ft_lstclear(&lst_a);
    //ft_lstclear(&lst_b);
    return 0;
}
