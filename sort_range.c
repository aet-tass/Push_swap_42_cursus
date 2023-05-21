#include "push_swap.h"

int	find_index(int *arr, int size, int num)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == num)
			return (index);
		index++;
	}
	return (-1);
}
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
		int max;
		int max_index;

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

void	sort_range(t_list **lst_a, t_list **lst_b, int end_range,
		int *soted_arr, int size)
{
	int		start;
	int		end;
	t_list	*top_node;
	int		top;
	int		index;

	start = 0;
	end = end_range;
	while (*lst_a)
	{
		top_node = *lst_a;
		top = *(int *)top_node->content;
		index = find_index(soted_arr, size, top);
		if (index >= start && index <= end)
		{
			pb(lst_a, lst_b, 1);
			start++;
			end++;
		}
		else if (index > end)
		{
			ra(lst_a, 1);
		}
		else if (index < start)
		{
			pb(lst_a, lst_b, 1);
			rb(lst_b, 1);
			start++;
			end++;
		}
	}
	sort_final_range(lst_a, lst_b);
}
