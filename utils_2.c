/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:17:07 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/27 22:26:31 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arguments(int argc, char **argv)
{
	char	*str;
	int		i;

	str = ft_strdup("");
	if (argc == 1)
		exit(0);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
	}
	return (str);
}

char	**split_arguments(char *str)
{
	return (ft_split(str, ' '));
}

t_list	*create_list(char **spt)
{
	t_list	*lst_a;
	int		i;
	int		num;
	void	*num_ptr;

	lst_a = NULL;
	i = 0;
	while (spt[i])
	{
		num = ft_atoi(spt[i]);
		num_ptr = (void *)malloc(sizeof(int));
		*(int *)num_ptr = num;
		ft_lstadd_back(&lst_a, ft_lstnew(num_ptr));
		i++;
	}
	return (lst_a);
}

t_list	*parse_arguments(int argc, char **argv)
{
	char	*str;
	char	**spt;
	t_list	*lst_a;
	int		i;

	i = 0;
	str = join_arguments(argc, argv);
	spt = split_arguments(str);
	if (spt[0] == NULL)
		ft_putstr_fd("Eroor\n", 2);
	free(str);
	lst_a = create_list(spt);
	while (spt[i] != NULL)
	{
		free(spt[i]);
		i++;
	}
	free(spt);
	return (lst_a);
}

int	find_index(int *arr, int size, int num)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == num)
			return (index);
		index++;
	}
	return (-1);
}
