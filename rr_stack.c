/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:06:52 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 00:39:25 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **lst, int check)
{
	t_list	*last;
	t_list	*prev_last;

	if (lst && *lst && (*lst)->next)
	{
		last = *lst;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *lst;
		*lst = last;
		if (check == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **lst, int check)
{
	t_list	*last;
	t_list	*prev_last;

	if (lst && *lst && (*lst)->next)
	{
		last = *lst;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *lst;
		*lst = last;
		if (check == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **lst_a, t_list **lst_b, int check)
{
	rra(lst_a, 0);
	rrb(lst_b, 0);
	if (check == 1)
		write(1, "rrr\n", 4);
}
