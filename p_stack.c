/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:24:02 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/13 00:04:05 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_list **lst_a, t_list **lst_b, int check)
{
    if (*lst_b == NULL)
        return ;
    t_list *tmp;

    tmp = (*lst_b)->next;
    (*lst_b)->next = *lst_a;
    *lst_a = *lst_b;
    *lst_b = tmp;
    if (check)
        printf("pa\n");
}

void    pb(t_list **lst_a, t_list **lst_b, int check)
{
    t_list *tmp;

    if (*lst_a == NULL)
        return ;
    tmp = *lst_a;
    *lst_a = (*lst_a)->next;
    tmp->next = *lst_b;
    *lst_b = tmp;
    if (check == 1)
        printf("pb\n");
}
