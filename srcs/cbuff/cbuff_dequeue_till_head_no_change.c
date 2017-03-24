/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuff_dequeue_till_head_no_change.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:59:50 by cledant           #+#    #+#             */
/*   Updated: 2017/03/24 18:22:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline size_t		get_max_dequeue_size(t_cbuff *cbuff)
{
	size_t		max_d_size;

	if (cbuff->r_pos < cbuff->w_pos)
		max_d_size = cbuff->r_pos - cbuff->w_pos;
	else if (cbuff->r_pos > cbuff->w_pos)
		max_d_size = cbuff->size - cbuff->r_pos + cbuff->w_pos;
	else if (cbuff->r_pos == cbuff->w_pos && cbuff->overwrite == 0)
		max_d_size = 0;
	else
		max_d_size = cbuff->size;
	return (max_d_size);
}

size_t						cbuff_dequeue_till_head_no_change(t_cbuff *cbuff)
{
	size_t		max_d_size;
	size_t		first_half;
	size_t		second_half;

	if ((max_d_size = get_max_dequeue_size(cbuff)) == 0)
		return (0);
	ft_bzero(cbuff->dequeue_buff, cbuff->size);
	if (cbuff->w_pos > cbuff->r_pos)
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, max_d_size);
	else if ((cbuff->r_pos + max_d_size - 1) <= (cbuff->size - 1))
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, max_d_size);
	else
	{
		first_half = cbuff->size - cbuff->r_pos;
		second_half = cbuff->w_pos;
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, first_half);
		ft_memcpy(cbuff->dequeue_buff + first_half, cbuff->buff, second_half);
	}
	return (max_d_size);
}
