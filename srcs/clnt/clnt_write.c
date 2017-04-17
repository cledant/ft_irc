/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:03:20 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 14:15:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_write(t_cbuff *cbuff_write, int fd_sock)
{
	size_t		sent;

	if (cbuff_write->overwrite == 1)
	{
		//deco a faire ici
		return ;
	}
	cbuff_dequeue_till_head_no_change(cbuff_write);
	sent = send(fd_sock, cbuff_write->dequeue_buff, ft_strlen(
		cbuff_write->dequeue_buff), 0);
	cbuff_move_forward_read_head(cbuff_write, sent);
}
