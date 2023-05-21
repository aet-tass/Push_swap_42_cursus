/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:00:00 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 00:35:42 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		res *= 10;
		res = (res + str[i]) - '0';
		i++;
	}
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (res);
}
