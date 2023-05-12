/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:32:02 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/10 22:47:18 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

int	ft_printf(const char *, ...);
int	ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int is_integer(char *str);
int check_args(int argc, char **argv);
int	ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(int));
t_list	*ft_lstnew(int content);
void lst_print(t_list *lst);
void    sa(t_list **lst, int	check);
void    sb(t_list **lst ,int check);
void    ss(t_list **lst_a, t_list **lst_b, int	check);
void	ft_lstdelone(t_list *lst, void (*del)(int ));





#endif 
