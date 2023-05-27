/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:00:00 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/25 23:39:41 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

int	convert_to_int(const char *str, int *index)
{
	int	res;
	int	s;

	s = 0;
	res = 0;
	while (str[*index])
	{
		if (!ft_isdigit(str[*index]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		res *= 10;
		res = (res + str[*index]) - '0';
		(*index)++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\r')
		i++;
	sign = get_sign(str, &i);
	res = convert_to_int(str, &i);
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (res);
}
