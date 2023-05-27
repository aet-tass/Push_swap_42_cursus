/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:40:55 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/25 23:06:13 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	perform_operation(t_list **lst_a, t_list **lst_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0 && ft_strlen(line) == 3)
		sa(lst_a, 0);
	else if (ft_strncmp(line, "sb\n", 2) == 0 && ft_strlen(line) == 3)
		sb(lst_b, 0);
	else if (ft_strncmp(line, "ss\n", 2) == 0 && ft_strlen(line) == 3)
		ss(lst_a, lst_b, 0);
	else if (ft_strncmp(line, "pa\n", 2) == 0 && ft_strlen(line) == 3)
		pa(lst_a, lst_b, 0);
	else if (ft_strncmp(line, "pb\n", 2) == 0 && ft_strlen(line) == 3)
		pb(lst_a, lst_b, 0);
	else
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
}

void	ft_cmp(t_list **lst_a, t_list **lst_b, char *line)
{
	if (ft_strncmp(line, "ra\n", 2) == 0 && ft_strlen(line) == 3)
		ra(lst_a, 0);
	else if (ft_strncmp(line, "rb\n", 2) == 0 && ft_strlen(line) == 3)
		rb(lst_b, 0);
	else if (ft_strncmp(line, "rr\n", 2) == 0 && ft_strlen(line) == 3)
		rr(lst_a, lst_b, 0);
	else if (ft_strncmp(line, "rra\n", 3) == 0 && ft_strlen(line) == 4)
		rra(lst_a, 0);
	else if (ft_strncmp(line, "rrb\n", 3) == 0 && ft_strlen(line) == 4)
		rrb(lst_b, 0);
	else if (ft_strncmp(line, "rrr\n", 3) == 0 && ft_strlen(line) == 4)
		rrr(lst_a, lst_b, 0);
	else
		perform_operation(lst_a, lst_b, line);
}
