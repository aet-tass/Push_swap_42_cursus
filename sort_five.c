/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:31:50 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 00:11:57 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = *(int *)lst->content;
	lst = lst->next;
	while (lst)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		lst = lst->next;
	}
	return (min);
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	int	min;
	int	i;

	while (ft_lstsize(*lst_a) > 3)
	{
		min = get_min(*lst_a);
		i = 0;
		while (*(int *)(*lst_a)->content != min)
		{
			ra(lst_a, 1);
			i++;
		}
		pb(lst_a, lst_b, 1);
		if (i > (ft_lstsize(*lst_a) / 2))
			rra(lst_a, 1);
	}
	sort_small(lst_a);
	while (*lst_b != NULL)
	{
		pa(lst_a, lst_b, 1);
	}
}
