/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:48 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/27 12:08:48 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int				space_count(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (ft_isdigit(str[i - 1]) == 0 || str[0] == ' ')
		return (69);
	return (j);
}

int				name_check(char *str)
{
	int	i;

	i = 0;
	if (space_count(str) == 69 && !check_comment(str))
		return (0);
	if (space_count(str) != 2)
		return (0);
	while (str[i] != ' ')
		i++;
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			std_err(RED" : coords must be digits.\n");
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i])
		std_err(RED" : bad coordinates.\n");
	return (1);
}

char			*get_name(char *str)
{
	return ((ft_strsplit(str, ' '))[0]);
}

t_lemin			get_map(t_lemin m)
{
	m.map = malloc_2d(m.map);
	m.s = 0;
	while (get_next_line(0, &m.in[m.count[0]]))
	{
		if (m.map[m.s][0] != '#' && m.map[m.s][0] != 'L')
			m.map[m.s][0] = ' ';
		if (name_check(m.in[m.count[0]]) == 1)
			m.map[m.s++] = ft_strcat(m.map[m.s], get_name(m.in[m.count[0]]));
		else if (check_comment(m.in[m.count[0]]) == 2)
			m.map[m.s][0] = '#';
		else if (check_comment(m.in[m.count[0]]) == 3)
			m.map[m.s][0] = 'L';
		else if (check_comment(m.in[m.count[0]]) == 1
				|| check_comment(m.in[m.count[0]]) == 4)
			m.s = m.s;
		else
			link_val(m);
		m.count[0]++;
	}
	std_err(RED" : insufficient data.\n");
	return (m);
}
