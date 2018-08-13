/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:56:54 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/13 17:46:28 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int		check_invalid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
int		get_number(void)
{
	int		ret;
	long	ant;
	char	*str;

	ret = 1;
	ant = 0;
	while (get_next_line(0, &str) && ret)
	{
		if (check_comment(str) == 1 || check_comment(str) == 4)
			ant = 0;
		else if (check_invalid(str) == 1)
			std_err(": number of ants must be a digit.\n");
		else
		{
			ant = ft_atoi(str);
			free(str);
			break ;
		}
		free(str);
	}
	if (ant > 2147483647 || ant < -2147483648 || !ant)
		std_err(": ants can not overflow, nor can they be.\n");
	return ((int)ant);
}
