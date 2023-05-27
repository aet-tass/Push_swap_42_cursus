/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:15:26 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/25 20:47:11 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_triplet(t_list **lst, int a, int b, int c)
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

void	sort_small(t_list **lst)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	int		s[3];

	if (ft_lstsize(*lst) == 3)
	{
		node_a = *lst;
		s[0] = *(int *)(node_a->content);
		node_b = node_a->next;
		s[1] = *(int *)(node_b->content);
		node_c = node_b->next;
		s[2] = *(int *)(node_c->content);
		compare_triplet(lst, s[0], s[1], s[2]);
	}
}
