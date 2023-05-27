/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:33:55 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/27 19:46:37 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
t_list	*parse_arguments(int argc, char **argv);
void	ft_cmp(t_list **lst_a, t_list **lst_b, char *line);
char	*get_next_line(int fd);

#endif
