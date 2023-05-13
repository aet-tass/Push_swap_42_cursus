/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:31:50 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/14 00:39:18 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_list **lst_a, t_list **lst_b)
{
    if (ft_lstsize(*lst_a) == 2)
    {
        if (*(int *)(*lst_a)->content > *(int *)(*lst_a)->next->content)
            sa(lst_a, 1);
        return;
    }
    pb(lst_a, lst_b, 1);
    pb(lst_a, lst_b, 1);
    sort_small(lst_a);
    pa(lst_a, lst_b, 1);
    if (*(int *)(*lst_a)->content > *(int *)(*lst_a)->next->content)
        sa(lst_a, 1);
    pa(lst_a, lst_b, 1);
    if (*(int *)(*lst_a)->content > *(int *)(*lst_a)->next->content)
        sa(lst_a, 1);
}
