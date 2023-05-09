/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:30:50 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/09 23:37:55 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list **lst, int	check)
{
    t_list  *tmp;

    if (*lst && (*lst)->next)
    {
        tmp = (*lst)->next;
        (*lst)->next = tmp->next;
        tmp->next = *lst;
        *lst = tmp;
    }
	if (check != 0)
		printf("sa\n");
}
void    sb(t_list **lst ,int check)
{
    sa(lst);
	if (check != 0)
		printf("sb\n")
}

void    ss(t_list **lst_a, t_list **lst_b)
{
    sa(lst_a, 0);
    sa(lst_b, 0);
}

