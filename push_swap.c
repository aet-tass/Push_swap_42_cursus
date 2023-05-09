/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/09 23:35:42 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     main(int argc, char **argv)
{
    t_list  *lst_a;    // Pointer to the head node of list A
    t_list  *lst_b;    // Pointer to the head node of list B
    int     i;

    lst_a = NULL;
    lst_b = NULL;

    // Check the provided arguments
    if (check_args(argc, argv))
    {
        // Populate list A with provided arguments
        for (i = 1; i < argc; i++) {
            ft_lstadd_back(&lst_a, ft_lstnew((void *)ft_atoi(argv[i])));
        }

        // Example usage of sorting functions
        sa(&lst_a);
        sb(&lst_b);
        ss(&lst_a, &lst_b);

        // Print out resulting lists
        printf("List A: ");
        lst_print(lst_a);
        printf("\n");

        printf("List B: ");
        lst_print(lst_b);
        printf("\n");
    }

    // Free memory and exit program
    ft_lstclear(&lst_a);
    ft_lstclear(&lst_b);
    return 0;
}
