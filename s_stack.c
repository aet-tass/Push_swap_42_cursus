/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:30:50 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 00:38:16 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst, int check)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
	}
	if (check != 0)
		write(1, "sa\n", 3);
}
void	sb(t_list **lst, int check)
{
	sa(lst, 0);
	if (check != 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b, int check)
{
	sa(lst_a, 0);
	sa(lst_b, 0);
	if (check != 0)
		write(1, "ss", 3);
}
