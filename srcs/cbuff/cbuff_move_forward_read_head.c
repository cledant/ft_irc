/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuff_move_forward_read_head.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:24:06 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 11:38:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline size_t		get_max_dequeue_size(t_cbuff *cbuff)
{
	size_t		max_d_size;

	if (cbuff->r_pos < cbuff->w_pos)
		max_d_size = cbuff->w_pos - cbuff->r_pos;
	else if (cbuff->r_pos > cbuff->w_pos)
		max_d_size = cbuff->size - cbuff->r_pos + cbuff->w_pos;
	else if (cbuff->r_pos == cbuff->w_pos && cbuff->enqueue_cumul == 0 &&
			cbuff->overwrite == 0)
		max_d_size = 0;
	else
		max_d_size = cbuff->size;
	return (max_d_size);
}

void						cbuff_move_forward_read_head(t_cbuff *cbuff,
								const size_t f_size)
{
	size_t		max_d_size;

	if ((max_d_size = get_max_dequeue_size(cbuff)) == 0)
		return ;
	if (f_size < max_d_size)
		max_d_size = f_size;
	cbuff->r_pos = (cbuff->r_pos + max_d_size) % cbuff->size;
	cbuff->overwrite = 0;
	cbuff->enqueue_cumul -= max_d_size;
}
