/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:58:01 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/09 20:10:06 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_integer(const char *str)
{
    if (*str == '-' || *str == '+') {
        str++;
    }
    if (!*str) {
        return 0;
    }
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

int check_args(int argc, char **argv)
{
    int	i;
   	int	num;

    if (argc < 2)
   	{
        printf("Error: Please provide at least one integer to sort.\n");
        return 0;
    }
	i = 1;
	while (i++<argc)
	{
        if (!is_integer(argv[i])) {
            printf("Error: '%s' is not a valid integer.\n", argv[i]);
            return 0;
        }
        num = ft_atoi(argv[i]);
        if (num < INT_MIN || num > INT_MAX) {
            printf("Error: '%s' is out of range for integers.\n", argv[i]);
            return 0;
        }
    }

    return 1;
}
