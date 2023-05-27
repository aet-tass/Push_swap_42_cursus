/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:05:36 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/27 21:09:52 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_sorted_array(t_list *lst_a)
{
	t_list	*current;
	int		*sorted_arr;
	int		i;

	sorted_arr = (int *)malloc(sizeof(int) * ft_lstsize(lst_a));
	if (sorted_arr == NULL)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (NULL);
	}
	i = 0;
	current = lst_a;
	while (current != NULL)
	{
		sorted_arr[i] = *(int *)(current->content);
		current = current->next;
		i++;
	}
	return (sorted_arr);
}

void	perform_sort(t_list **lst_a, t_list **lst_b, int *sorted_arr)
{
	int	size;

	size = ft_lstsize(*lst_a);
	if (size == 2)
	{
		if (!is_sorted(*lst_a))
			sa(lst_a, 1);
	}
	else if (size <= 3)
		sort_small(lst_a);
	else if (size <= 5)
		sort_five(lst_a, lst_b);
	else if (size <= 100)
		sort_range(lst_a, lst_b, 19, sorted_arr);
	else if (size <= 500)
		sort_range(lst_a, lst_b, 35, sorted_arr);
}

void	free_lists(t_list **lst_a, t_list **lst_b)
{
	ft_lstclear(lst_a);
	ft_lstclear(lst_b);
}

int	perform_sorting(t_list *lst_a)
{
	t_list	*lst_b;
	int		*sorted_arr;

	lst_b = NULL;
	sorted_arr = create_sorted_array(lst_a);
	if (sorted_arr == NULL)
		return (1);
	perform_sort(&lst_a, &lst_b, sorted_arr);
	free(sorted_arr);
	free_lists(&lst_a, &lst_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;

	lst_a = parse_arguments(argc, argv);
	if (lst_a == NULL)
		return (1);
	if (check_duplicates(lst_a) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (is_sorted(lst_a) == 1)
		return (0);
	return (perform_sorting(lst_a));
}
