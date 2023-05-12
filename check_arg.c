/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:58:01 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/10 20:38:30 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int check_args(int argc, char **argv)
{
    int	i;
   	int	num;
   //(void)argv;
	if (argc < 2)
   	{
        ft_printf("Error: Please provide at least one integer to sort.\n");
        return 0;
    }
	i = 1;
	while (i < argc)
	{
        num = ft_atoi(argv[1]);
		printf("%d\n", num);
        if (isdigit(num)) {
            ft_printf("Error");
            return 0;
        }
	  i++;
    }

    return 1;
}
