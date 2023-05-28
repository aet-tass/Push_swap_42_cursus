/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:58:55 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/28 01:05:43 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void    ft_swap(int *arr, int i, int j)
{
    int    tmp;

    while (i < j)
    {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
}

void    quicksort(int *arr, int left, int right)
{
    int    i;
    int    j;
    int    pivot;

    i = left;
    j = right;
    pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            ft_swap(arr, i, j);
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort (arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int	*create_sorted_array(t_list *lst_a)
{
	t_list	*current;
	int		*sorted_arr;
	int		i;
	int		j;

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
