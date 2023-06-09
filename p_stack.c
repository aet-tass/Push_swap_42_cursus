/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:24:02 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/21 23:33:36 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b, int check)
{
	t_list	*tmp;

	if (*lst_b == NULL)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	if (check == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **lst_a, t_list **lst_b, int check)
{
	t_list	*tmp;

	if (*lst_a == NULL)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	if (check == 1)
		write(1, "pb\n", 3);
}
