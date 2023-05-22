/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:53:35 by aet-tass          #+#    #+#             */
/*   Updated: 2023/01/13 17:41:01 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
			new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free (s1);
	return (new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len)
		{
			new_str[i] = s[start];
			i++;
			start++;
		}
		new_str[i] = '\0';
	}
	else
		new_str[0] = '\0';
	free (s);
	return (new_str);
}
