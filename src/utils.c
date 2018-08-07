/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:06:19 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/07 15:41:33 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	std_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int		check_comment(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (ft_strcmp(str, "##start") == 0)
		return (2);
	else if (ft_strcmp(str, "##end") == 0)
		return (3);
	else if (str[0] == '#')
		return (4);
	else
		return (0);
}

char	**malloc_2d(char **map)
{
	int i;

	i = 0;
	while (i < 2001)
	{
		map[i] = (char *)malloc(sizeof(char) * 20);
		i++;
	}
	return (map);
}
