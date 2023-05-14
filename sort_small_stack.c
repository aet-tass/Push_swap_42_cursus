/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:15:26 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/14 19:03:04 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_small(t_list **lst)
{
    if (ft_lstsize(*lst) == 2 && *(int *)((*lst)->content) > *(int *)((*lst)->next->content))
        sa(lst, 1);
    else if (ft_lstsize(*lst) == 3)
    {
        t_list *node_a = *lst;
        t_list *node_b = node_a->next;
        t_list *node_c = node_b->next;

        int a = *(int *)(node_a->content);
        int b = *(int *)(node_b->content);
        int c = *(int *)(node_c->content);

        if (a > b && b < c && a < c)
            sa(lst, 1);
        else if (a > b && b > c && a > c)
        {
            sa(lst, 1);
            rra(lst, 1);
        }
        else if (a > b && b < c && a > c)
            ra(lst, 1);
        else if (a < b && b > c && a < c)
        {
            sa(lst, 1);
            ra(lst, 1);
        }
        else if (a < b && b > c && a > c)
            rra(lst, 1);
    }
}



