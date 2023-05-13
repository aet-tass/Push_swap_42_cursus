/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:00:33 by aet-tass          #+#    #+#             */
/*   Updated: 2023/05/13 00:19:26 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_check_duplicates(int num, int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            ft_printf("Error");
            return (1);
        }
    }
    arr[size] = num;
    return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	res;
    int nums[100];
    int size = 0;

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
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res = (res + str[i]) - '0';
		i++;
	}
	 if (ft_check_duplicates(res, nums, size))
    {
        exit(1);
    }
    size++;
	if (res < INT_MIN || res > INT_MAX)
	{
		ft_printf("Error\n");
		exit (1);
	}
	return (res * sign);
}

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char                    *new_str;
        unsigned int    i;

        i = 0;
        if (!s)
                return (NULL);
        new_str = (char *)malloc(len + 1);
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
        return (new_str);
}

static int      count_words(const char *str, char c)
{
        int     i;
        int     counter;

        counter = 0;
        i = 0;
        while (str[i])
        {
                if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
                        counter++;
                i++;
        }
        return (counter);
}

char    **ft_split(char const *s, char c)
{
        char    **dest;
        int             i;
        int             j;
        int             len_s;

        i = 0;
        j = 0;
        dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
        if (!dest)
                return (NULL);
        while (j < count_words(s, c))
        {
                while (s[i] && s[i] == c)
                        i++;
                len_s = 0;
                while (s[i] && s[i] != c)
                {
                        len_s++;
                        i++;
                }
                dest[j] = ft_substr(s, (i - len_s), len_s);
                j++;
        }
        dest[j] = NULL;
        return (dest);
}
