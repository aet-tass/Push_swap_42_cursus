/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:32:02 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/22 01:32:44 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		is_integer(char *str);
int		check_args(int argc, char **argv);
void	lst_print(t_list *lst);
void	sa(t_list **lst, int check);
void	sb(t_list **lst, int check);
void	ss(t_list **lst_a, t_list **lst_b, int check);
int		check_duplicates(t_list *head);
int		is_sorted(t_list *head);
void	ra(t_list **lst, int check);
void	rb(t_list **lst, int check);
void	rr(t_list **lst_a, t_list **lst_b, int check);
void	pa(t_list **lst_a, t_list **lst_b, int check);
void	pb(t_list **lst_a, t_list **lst_b, int check);
void	rra(t_list **lst, int check);
void	rrb(t_list **lst, int check);
void	rrr(t_list **lst_a, t_list **lst_b, int check);
void	sort_small(t_list **lst);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	sort_range(t_list **lst_a, t_list **lst_b, int end_range, int *a, int s);
t_list *parse_arguments(int argc, char **argv);
int	find_index(int *arr, int size, int num);

#endif
