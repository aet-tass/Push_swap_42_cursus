/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:15:56 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:16:14 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*sort_arr(int *arr, int n)
{
	int	i;
	int	j;
	int	sorted;

	i = 0;
	j = 0;
	sorted = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				sorted = 1;
			}
			j++;
		}
		if (sorted == 0)
			break ;
		i++;
	}
	return (arr);
}
