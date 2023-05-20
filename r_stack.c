/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_stack.c            ########    ## #     ##    ##             ## ##     */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:04:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/   ########    ##      # #    ##    ##  ##           ##    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
	if (check == 1)
		printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b, int check)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	if (check == 1)
		printf("rr\n");
}
