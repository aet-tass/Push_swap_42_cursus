#include "push_swap.h"

int find_index(int *arr, int size, int num)
{
    int index = 0;

    while (index < size)
    {
        if (arr[index] == num)
            return index;
        index++;
    }

    // Element not found in the list
    return -1;
}

int find_max_value(t_list *lst)
{
    int max = *(int *)(lst->content); // Assuming the content of each node is of type `int`
    lst = lst->next;

    while (lst)
    {
        int value = *(int *)(lst->content);
        if (value > max)
            max = value;
        lst = lst->next;
    }

    return max;
}

void sort_final_range(t_list **lst_a, t_list **lst_b, int *sorted_arr, int size)
{
    while (*lst_b)
    {
        int max = find_max_value(*lst_b);
        int max_index = find_index(sorted_arr, size, max);

        if (max_index == 1)
        {
            pa(lst_b, lst_a, 1);
        }
        else if (max_index <= ft_lstsize(*lst_b) / 2)
        {
            rb(lst_b, 1);
        }
        else
        {
            rrb(lst_b, 1);
        }
    }
}

void sort_range(t_list **lst_a, t_list **lst_b, int end_range, int *soted_arr, int size)
{
    int start = 0;
    int end = end_range;
    t_list *top_node = *lst_a;

    while (top_node != NULL)
    {
        int top = *(int *)top_node->content;
        // printf("top: [%d]\n", top);
        int index = find_index(soted_arr, size, top);
        top_node = top_node->next;
        if (index >= start && index <= end)
        {
            pb(lst_a, lst_b, 0);
            start++;
            end++;
        }
        else if (index > end)
        {
            ra(lst_a, 1);
        }
        else
        {
            pb(lst_a, lst_b, 1);
            rb(lst_b, 1);
            start++;
            end++;
        }
    }
    // t_list *node = *lst_b;
    // while (node)
    // {
    //     int n = *(int *)node->content;
    //     printf("b: %d\n", n);
    //     node = node->next;
    // }
    // printf("\n");
    // sort_final_range(lst_a, lst_b, soted_arr, size);
}

