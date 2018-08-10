/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:08:57 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/10 11:50:32 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int		main(void)
{
	int		ants;
	t_lemin	map;

	ants = get_number();
	map = get_map();
	(void)ants;
	(void)map;
}
