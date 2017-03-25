/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuff_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:28:57 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 10:52:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	cbuff_flush(t_cbuff *cbuff)
{
	ft_bzero(cbuff->buff, cbuff->size + 1);
	ft_bzero(cbuff->enqueue_buff, cbuff->size + 1);
	ft_bzero(cbuff->dequeue_buff, cbuff->size + 1);
	cbuff->r_pos = 0;
	cbuff->w_pos = 0;
	cbuff->overwrite = 0;
	cbuff->enqueue_cumul = 0;
}
