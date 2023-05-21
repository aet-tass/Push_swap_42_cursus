/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:58:01 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/21 19:40:28 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicates(t_list *head)
{
    t_list *current;
    t_list *runner;
    int current_val;
    int runner_val;

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

int is_sorted(t_list *head)
{
    t_list  *current;
    int prev_val;
    int curr_val;

    current = head;
    prev_val = 0;
    while (current)
    {
        curr_val = *((int *)current->content);
        if (curr_val < prev_val)
            return (0);
        prev_val = curr_val;
        current = current->next;
    }
    return (1);
}
