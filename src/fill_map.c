/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/08 16:23:06 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int				dash_cnt(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	return (j);
}

int				link_val(t_lemin map)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (dash_cnt(map.first) != 1)
		return (0);
	return(10);

}

t_lemin			fill_map(t_lemin map)
{
	return (map);
}


