/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:49:43 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/27 17:44:54 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_stack(t_list *lst_b, int num)
{
	int	index;

	index = 0;
	while (*(int *)lst_b->content != num)
	{
		index++;
		lst_b = lst_b->next;
	}
	return (index);
}

int	find_max_value(t_list *lst)
{
	int	max;
	int	value;

	max = *(int *)(lst->content);
	lst = lst->next;
	while (lst)
	{
		value = *(int *)(lst->content);
		if (value > max)
			max = value;
		lst = lst->next;
	}
	return (max);
}

void	sort_final_range(t_list **lst_a, t_list **lst_b)
{
	int	max;
	int	max_index;

	while (*lst_b)
	{
		while (ft_lstsize(*lst_b))
		{
			max = find_max_value(*lst_b);
			max_index = find_index_stack(*lst_b, max);
			if (max_index <= ft_lstsize(*lst_b) / 2)
				while (find_index_stack(*lst_b, max) != 0)
					rb(lst_b, 1);
			else
				while (find_index_stack(*lst_b, max) != 0)
					rrb(lst_b, 1);
			pa(lst_a, lst_b, 1);
		}
	}
}

void	push_elements(t_list **lst_a, t_list **lst_b, int *start, int *end)
{
	pb(lst_a, lst_b, 1);
	(*start)++;
	(*end)++;
}

void	sort_range(t_list **lst_a, t_list **lst_b, int end_rge, int *srtd_arr)
{
	int		size;
	int		intr[2];
	t_list	*top_node;
	int		top;
	int		index;

	size = ft_lstsize(*lst_a);
	intr[0] = 0;
	intr[1] = end_rge;
	while (*lst_a)
	{
		top_node = *lst_a;
		top = *(int *)top_node->content;
		index = find_index(srtd_arr, size, top);
		if (index >= intr[0] && index <= intr[1])
			push_elements(lst_a, lst_b, &intr[0], &intr[1]);
		else if (index > intr[1])
			ra(lst_a, 1);
		else if (index < intr[0])
		{
			push_elements(lst_a, lst_b, &intr[0], &intr[1]);
			rb(lst_b, 1);
		}
	}
	sort_final_range(lst_a, lst_b);
}
