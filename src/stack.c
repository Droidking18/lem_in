/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:30:05 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/23 11:26:12 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		push(int *stack, int *top, int nxt_room)
{
	(*top)++;
	stack[*top] = nxt_room;
}

void		pop(int *top)
{
	(*top)--;
}