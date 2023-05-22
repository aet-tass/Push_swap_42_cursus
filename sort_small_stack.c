/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:15:26 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:23:51 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compare_triplet(t_list **lst, int a, int b, int c)
{
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

void sort_small(t_list **lst)
{
    if (ft_lstsize(*lst) == 3)
    {
        t_list *node_a = *lst;
        int a = *(int *)(node_a->content);
        t_list *node_b = node_a->next;
        int b = *(int *)(node_b->content);
        t_list *node_c = node_b->next;
        int c = *(int *)(node_c->content);

        compare_triplet(lst, a, b, c);
    }
}
