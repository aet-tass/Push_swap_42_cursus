/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:42:17 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/11 00:42:24 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if (argc == 1)
        return (0);
    if (!init_stacks(&stack_a, &stack_b, argc, argv))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    if (is_sorted(stack_a))
        return (0);
    if (stack_a.size <= 3)
        sort_small(&stack_a, &stack_b);
    else if (stack_a.size <= 5)
        sort_medium(&stack_a, &stack_b);
    else
        sort_large(&stack_a, &stack_b);
    clear_stacks(&stack_a, &stack_b);
    return (0);
}

