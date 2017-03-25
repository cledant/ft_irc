/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_fd_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:34:54 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 14:34:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_init_fd_free(t_fd *fd, const t_switch type)
{
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	ft_bzero(fd->nick, MAX_NICK_LEN + 1);
	ft_bzero(fd->joined_chan, MAX_NB_CHAN);
	if (type == SET)
	{
		if ((fd->cbuff_read = cbuff_create(CBUFF_SIZE)) == NULL)
			return (0);
		if ((fd->cbuff_write = cbuff_create(CBUFF_SIZE)) == NULL)
			return (0);
	}
	else if (type == RESET)
	{
		cbuff_flush(fd->cbuff_read);	
		cbuff_flush(fd->cbuff_write);
	}
	else
		return (0);
	return (1);
}
