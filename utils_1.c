/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:29:59 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/10 22:46:58 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*courant;

	if (!lst)
		return (NULL);
	courant = lst;
	while (courant->next)
		courant = courant->next;
	return (courant);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	(*node).content = content;
	(*node).next = NULL;
	return (node);
}
void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void lst_print(t_list *lst)
{
    while (lst)
    {
        printf("%d ", (lst->content));
        lst = lst->next;
    }
}

void	ft_lstdelone(t_list *lst, void (*del)(int ))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->content);
		free(lst);
	}
}
