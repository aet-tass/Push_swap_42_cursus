/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:40:10 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/25 22:36:14 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **lst, int check)
{
	t_list	*first;
	t_list	*last;

	if (*lst && (*lst)->next)
	{
		first = *lst;
		last = ft_lstlast(*lst);
		*lst = first->next;
		last->next = first;
		first->next = NULL;
		if (check == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list **lst, int check)
{
	t_list	*temp;
	t_list	*last;

	if (*lst && (*lst)->next)
	{
		last = ft_lstlast(*lst);
		temp = *lst;
		*lst = (*lst)->next;
		last->next = temp;
		temp->next = NULL;
		if (check == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **lst_a, t_list **lst_b, int check)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	if (check == 1)
		write(1, "rr\n", 3);
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
