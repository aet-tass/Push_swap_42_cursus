#include "push_swap.h"

int find_index(t_list *lst, int num)
{
    int index = 0;
    t_list *current = lst;

    while (current != NULL)
    {
        int *data = (int *)current->content;
        if (*data == num)
            return index;
        index++;
        current = current->next;
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

void sort_final_range(t_list **lst_a, t_list **lst_b)
{
    while (*lst_b)
    {
        int max = find_max_value(*lst_b);
        int max_index = find_index(*lst_b, max);

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

void sort_range(t_list **lst_a, t_list **lst_b, int end_range)
{
    int start = 0;
    int end = end_range;
//    int size = ft_lstsize(*lst_a);

    while (start <= end)
    {
        t_list *top_node = *lst_a;
        int top = *(int *)top_node->content;
        int index = find_index(*lst_a, top);

        if (index >= start && index <= end)
        {
            pb(lst_a, lst_b, 1);
        }
        else if (index > end)
        {
            ra(lst_a, 1);
        }
        else
        {
            ra(lst_a, 1);
            end--;
        }
    }

    sort_final_range(lst_a, lst_b);
}

