/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:31:50 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/21 21:34:14 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(t_list *lst)
{
    int min;

    if (!lst)
        return (0);

    min = *(int *)lst->content;
    lst = lst->next;
    while (lst)
    {
        if (*(int *)lst->content < min)
            min = *(int *)lst->content;
        lst = lst->next;
    }
    return (min);
}

void sort_five(t_list **lst_a, t_list **lst_b)
{
    int min;
    int i;


/* Step 1: Sends the top two numbers from Stack A to Stack B
This loop takes the first two numbers from the top of Stack A and moves them to
Stack B. It then finds the minimum number in Stack A and rotates Stack A until the
minimum number is at the top. It then pushes the minimum number to Stack B.
Finally, if the number of rotations was greater than half of the size of Stack A, it
rotates Stack A in the opposite direction to put the top of the stack back to its
original position.
*/

    while (ft_lstsize(*lst_a) > 3)
    {
        min = get_min(*lst_a);
        i = 0;
        while (*(int *)(*lst_a)->content != min)
        {
            ra(lst_a, 1);
            i++;
        }
        pb(lst_a, lst_b, 1);
        if (i > (ft_lstsize(*lst_a) / 2))
            rra(lst_a, 1);
    }
    /*Step 2-3: Uses the logic from 3 Random Numbers to sort the numbers in A.
    This step uses the sort_small function you provided to sort the remaining
     three numbers in Stack A.


    */
    sort_small(lst_a);

    /*This loop takes the numbers from Stack B and pushes them onto Stack A. It then
    checks if the top two numbers on Stack A are in the correct order and swaps them
    if they are not.
    */
    while (*lst_b != NULL)
    {
        pa(lst_a, lst_b, 1);
        if ((*lst_a)->next != NULL && *(int *)(*lst_a)->content > *(int *)(*lst_a)->next->content)
            sa(lst_a, 1);
    }
}
