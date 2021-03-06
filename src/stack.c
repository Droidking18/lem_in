/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:30:05 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/27 09:45:27 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		push(int *stack, int *top, int nxt_room, int *swtch)
{
	(*top)++;
	stack[*top] = nxt_room;
	(*swtch) = 1;
}

void		pop(int *top)
{
	if (*top > -1)
		(*top)--;
	else
		std_err(RED" : No possible route.\n");
}

void		reset(int *swtch, int *j)
{
	if (*swtch)
	{
		(*swtch) = 0;
		(*j) = 0;
	}
	else
		(*j)++;
}
