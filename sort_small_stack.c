/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:15:26 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/21 23:41:46 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **lst)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	int		a;
	int		b;
	int		c;

	// if (ft_lstsize(*lst) == 2
			&& *(int *)((*lst)->content) > *(int *)((*lst)->next->content))
	//     sa(lst, 1);
	if (ft_lstsize(*lst) == 3)
	{
		node_a = *lst;
		node_b = node_a->next;
		node_c = node_b->next;
		a = *(int *)(node_a->content);
		b = *(int *)(node_b->content);
		c = *(int *)(node_c->content);
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
