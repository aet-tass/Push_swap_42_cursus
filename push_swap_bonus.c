/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:23:30 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/25 22:55:34 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*join_arguments(int argc, char **argv)
{
	char	*str;
	int		i;

	str = ft_strdup("");
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

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*line;

	lst_b = NULL;
	lst_a = parse_arguments(argc, argv);
	if (lst_a == NULL)
		return (1);
	if (check_duplicates(lst_a) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_cmp(&lst_a, &lst_b, line);
		free(line);
	}
	if (is_sorted(lst_a) == 1)
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
