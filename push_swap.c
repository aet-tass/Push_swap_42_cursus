/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c          ########    ## #     ##    ##             ## ##     */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/   ########    ##      # #    ##    ##  ##           ##    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_list  *lst_a;
    t_list  *lst_b;
    int     i;


    lst_a = NULL;
    lst_b = NULL;
    i = 1;
    (void)lst_b;
    if (argc >= 2)
    {
        while (i < argc)
        {
            int num = atoi(argv[i]);
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
         if (ft_lstsize(lst_a) <= 3)
			 sort_small(&lst_a);
		 
	 else if (ft_lstsize(lst_a) <= 5)
            sort_five(&lst_a, &lst_b);
	 else if (ft_lstsize(lst_a) <= 100)
			sort_range(&lst_a, &lst_b, 19);
	else if (ft_lstsize(lst_a) <= 500)
			sort_range(&lst_a, &lst_b, 35);



        //sa(&lst_a, 1);
        //sb(&lst_b, 1);
        //ss(&lst_a, &lst_b, 1);

        // Print out resulting lists
        printf("List A: ");
       lst_print(lst_a);
       printf("\n");
        //ft_printf("List B: ")
        //lst_print(lst_b);
        //ft_printf("\n");
    }
    else
        return (1);

    // Free memory and exit program
    //ft_lstclear(&lst_a);
    //ft_lstclear(&lst_b);
    return (0);
}
