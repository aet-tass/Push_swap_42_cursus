/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:20:24 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/27 21:31:56 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_duplicates(t_list *head)
{
	t_list	*current;
	t_list	*runner;
	int		current_val;
	int		runner_val;

	current = head;
	while (current)
	{
		current_val = *(int *)current->content;
		runner = current->next;
		while (runner)
		{
			runner_val = *(int *)runner->content;
			if (current_val == runner_val)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
int	is_sorted(t_list *head)
{
	t_list	*current;
	int		prev_val;
	int		curr_val;

	current = head;
	prev_val = INT_MIN;
	while (current)
	{
		curr_val = *((int *)current->content);
		if (curr_val < prev_val)
		{
			return (0);
		}
		prev_val = curr_val;
		current = current->next;
	}
	return (1);
}

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

void	ss(t_list **lst_a, t_list **lst_b, int check)
{
	sa(lst_a, 0);
	sa(lst_b, 0);
	if (check != 0)
		write(1, "ss", 3);
}
